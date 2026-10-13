#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chcrusherboulder_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B28: syscall     417
    recomp_syscall_handler(rdram, ctx, 0x80086B28);
    return;
    // 0x80086B2C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void gsmaker_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800714: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080071C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800720: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800724: jal         0x8080051C
    // 0x80800728: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    gsmaker_entrypoint_16(rdram, ctx);
        goto after_0;
    // 0x80800728: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080072C: bne         $v0, $zero, L_8080073C
    if (ctx->r2 != 0) {
        // 0x80800730: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080073C;
    }
    // 0x80800730: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800734: b           L_8080074C
    // 0x80800738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080074C;
    // 0x80800738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080073C:
    // 0x8080073C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800740: jal         0x80800338
    // 0x80800744: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    gsmaker_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x80800744: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080074C:
    // 0x8080074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800754: jr          $ra
    // 0x80800758: nop

    return;
    // 0x80800758: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_49(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802B28: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80802B2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802B30: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80802B34: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80802B38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802B3C: jal         0x800956B8
    // 0x80802B40: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_800956B8(rdram, ctx);
        goto after_0;
    // 0x80802B40: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x80802B44: jal         0x80800120
    // 0x80802B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800120_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80802B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80802B4C: jal         0x80800DF4
    // 0x80802B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DF4_bsbtrot(rdram, ctx);
        goto after_2;
    // 0x80802B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802B54: jal         0x808004B4
    // 0x80802B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_bsbtrot(rdram, ctx);
        goto after_3;
    // 0x80802B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80802B5C: jal         0x80800DC4
    // 0x80802B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800DC4_bsbtrot(rdram, ctx);
        goto after_4;
    // 0x80802B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80802B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B68: jal         0x808002A4
    // 0x80802B6C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808002A4_bsbtrot(rdram, ctx);
        goto after_5;
    // 0x80802B6C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80802B70: jal         0x800850A0
    // 0x80802B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoessuck_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80802B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80802B78: jal         0x80800438
    // 0x80802B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800438_bsbtrot(rdram, ctx);
        goto after_7;
    // 0x80802B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80802B80: jal         0x808008D0
    // 0x80802B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008D0_bsbtrot(rdram, ctx);
        goto after_8;
    // 0x80802B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80802B88: jal         0x8009EF10
    // 0x80802B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_9;
    // 0x80802B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80802B90: bne         $v0, $zero, L_80802BAC
    if (ctx->r2 != 0) {
        // 0x80802B94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802BAC;
    }
    // 0x80802B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B98: jal         0x8009BCD4
    // 0x80802B9C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_10;
    // 0x80802B9C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_10:
    // 0x80802BA0: beq         $v0, $zero, L_80802BAC
    if (ctx->r2 == 0) {
        // 0x80802BA4: nop
    
            goto L_80802BAC;
    }
    // 0x80802BA4: nop

    // 0x80802BA8: addiu       $s1, $zero, 0x17B
    ctx->r17 = ADD32(0, 0X17B);
L_80802BAC:
    // 0x80802BAC: jal         0x80800710
    // 0x80802BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800710_bsbtrot(rdram, ctx);
        goto after_11;
    // 0x80802BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80802BB4: bnel        $v0, $zero, L_80802BD0
    if (ctx->r2 != 0) {
        // 0x80802BB8: addiu       $s1, $zero, 0x17
        ctx->r17 = ADD32(0, 0X17);
            goto L_80802BD0;
    }
    goto skip_0;
    // 0x80802BB8: addiu       $s1, $zero, 0x17
    ctx->r17 = ADD32(0, 0X17);
    skip_0:
    // 0x80802BBC: jal         0x8008E40C
    // 0x80802BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E40C(rdram, ctx);
        goto after_12;
    // 0x80802BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80802BC4: bnel        $v0, $zero, L_80802BD4
    if (ctx->r2 != 0) {
        // 0x80802BC8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802BD4;
    }
    goto skip_1;
    // 0x80802BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80802BCC: addiu       $s1, $zero, 0x17
    ctx->r17 = ADD32(0, 0X17);
L_80802BD0:
    // 0x80802BD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802BD4:
    // 0x80802BD4: jal         0x80091A58
    // 0x80802BD8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_13;
    // 0x80802BD8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_13:
    // 0x80802BDC: beq         $v0, $zero, L_80802BF0
    if (ctx->r2 == 0) {
        // 0x80802BE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802BF0;
    }
    // 0x80802BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802BE4: jal         0x8080075C
    // 0x80802BE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8080075C_bsbtrot(rdram, ctx);
        goto after_14;
    // 0x80802BE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_14:
    // 0x80802BEC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80802BF0:
    // 0x80802BF0: jal         0x8008E35C
    // 0x80802BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_15;
    // 0x80802BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80802BF8: beq         $v0, $zero, L_80802C04
    if (ctx->r2 == 0) {
        // 0x80802BFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802C04;
    }
    // 0x80802BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802C00: addiu       $s1, $zero, 0x2D
    ctx->r17 = ADD32(0, 0X2D);
L_80802C04:
    // 0x80802C04: jal         0x80084E80
    // 0x80802C08: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    _bamovespline_entrypoint_1(rdram, ctx);
        goto after_16;
    // 0x80802C08: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_16:
    // 0x80802C0C: beq         $v0, $zero, L_80802C18
    if (ctx->r2 == 0) {
        // 0x80802C10: nop
    
            goto L_80802C18;
    }
    // 0x80802C10: nop

    // 0x80802C14: addiu       $s1, $zero, 0x71
    ctx->r17 = ADD32(0, 0X71);
L_80802C18:
    // 0x80802C18: jal         0x80084E90
    // 0x80802C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovespline_entrypoint_3(rdram, ctx);
        goto after_17;
    // 0x80802C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80802C20: beq         $v0, $zero, L_80802C2C
    if (ctx->r2 == 0) {
        // 0x80802C24: nop
    
            goto L_80802C2C;
    }
    // 0x80802C24: nop

    // 0x80802C28: addiu       $s1, $zero, 0x16
    ctx->r17 = ADD32(0, 0X16);
L_80802C2C:
    // 0x80802C2C: jal         0x80084E88
    // 0x80802C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovespline_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x80802C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80802C34: beql        $v0, $zero, L_80802C78
    if (ctx->r2 == 0) {
        // 0x80802C38: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802C78;
    }
    goto skip_2;
    // 0x80802C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80802C3C: jal         0x80084FE8
    // 0x80802C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_2(rdram, ctx);
        goto after_19;
    // 0x80802C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80802C44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802C48: bne         $v0, $at, L_80802C74
    if (ctx->r2 != ctx->r1) {
        // 0x80802C4C: addiu       $s1, $zero, 0x16
        ctx->r17 = ADD32(0, 0X16);
            goto L_80802C74;
    }
    // 0x80802C4C: addiu       $s1, $zero, 0x16
    ctx->r17 = ADD32(0, 0X16);
    // 0x80802C50: addiu       $s1, $sp, 0x28
    ctx->r17 = ADD32(ctx->r29, 0X28);
    // 0x80802C54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80802C58: jal         0x80085088
    // 0x80802C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoessuck_entrypoint_1(rdram, ctx);
        goto after_20;
    // 0x80802C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80802C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802C64: jal         0x800848A0
    // 0x80802C68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _badrone_entrypoint_23(rdram, ctx);
        goto after_21;
    // 0x80802C68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_21:
    // 0x80802C6C: b           L_80802C74
    // 0x80802C70: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_80802C74;
    // 0x80802C70: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80802C74:
    // 0x80802C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802C78:
    // 0x80802C78: jal         0x8009E5C8
    // 0x80802C7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_22;
    // 0x80802C7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_22:
    // 0x80802C80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802C84: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80802C88: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80802C8C: jr          $ra
    // 0x80802C90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80802C90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void bskazjump_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C20: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800C24: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(256, 0XC70) << 16);
    // 0x80800C28: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800C2C: jr          $ra
    // 0x80800C30: lw          $v0, 0xC70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(256, 0XC70));
    return;
    // 0x80800C30: lw          $v0, 0xC70($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(256, 0XC70));
;}
RECOMP_FUNC void func_800EDA2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDA2C: lh          $t6, 0x14($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X14);
    // 0x800EDA30: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EDA34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EDA38: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800EDA3C: nop

    // 0x800EDA40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EDA44: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x800EDA48: nop

    // 0x800EDA4C: bc1f        L_800EDA58
    if (!c1cs) {
        // 0x800EDA50: nop
    
            goto L_800EDA58;
    }
    // 0x800EDA50: nop

    // 0x800EDA54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EDA58:
    // 0x800EDA58: beq         $v0, $zero, L_800EDAEC
    if (ctx->r2 == 0) {
        // 0x800EDA5C: nop
    
            goto L_800EDAEC;
    }
    // 0x800EDA5C: nop

    // 0x800EDA60: lh          $t7, 0x1A($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X1A);
    // 0x800EDA64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EDA68: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800EDA6C: nop

    // 0x800EDA70: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800EDA74: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800EDA78: nop

    // 0x800EDA7C: bc1f        L_800EDA88
    if (!c1cs) {
        // 0x800EDA80: nop
    
            goto L_800EDA88;
    }
    // 0x800EDA80: nop

    // 0x800EDA84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EDA88:
    // 0x800EDA88: beq         $v0, $zero, L_800EDAEC
    if (ctx->r2 == 0) {
        // 0x800EDA8C: nop
    
            goto L_800EDAEC;
    }
    // 0x800EDA8C: nop

    // 0x800EDA90: lh          $t8, 0x18($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X18);
    // 0x800EDA94: lwc1        $f0, 0x8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EDA98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EDA9C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800EDAA0: nop

    // 0x800EDAA4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EDAA8: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x800EDAAC: nop

    // 0x800EDAB0: bc1f        L_800EDABC
    if (!c1cs) {
        // 0x800EDAB4: nop
    
            goto L_800EDABC;
    }
    // 0x800EDAB4: nop

    // 0x800EDAB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EDABC:
    // 0x800EDABC: beq         $v0, $zero, L_800EDAEC
    if (ctx->r2 == 0) {
        // 0x800EDAC0: nop
    
            goto L_800EDAEC;
    }
    // 0x800EDAC0: nop

    // 0x800EDAC4: lh          $t9, 0x1E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X1E);
    // 0x800EDAC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800EDACC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800EDAD0: nop

    // 0x800EDAD4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EDAD8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800EDADC: nop

    // 0x800EDAE0: bc1f        L_800EDAEC
    if (!c1cs) {
        // 0x800EDAE4: nop
    
            goto L_800EDAEC;
    }
    // 0x800EDAE4: nop

    // 0x800EDAE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EDAEC:
    // 0x800EDAEC: jr          $ra
    // 0x800EDAF0: nop

    return;
    // 0x800EDAF0: nop

;}
RECOMP_FUNC void func_80800EB8_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EBC: slti        $at, $a1, 0x144B
    ctx->r1 = SIGNED(ctx->r5) < 0X144B ? 1 : 0;
    // 0x80800EC0: bne         $at, $zero, L_80800EE4
    if (ctx->r1 != 0) {
        // 0x80800EC4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800EE4;
    }
    // 0x80800EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EC8: addiu       $at, $zero, 0x144C
    ctx->r1 = ADD32(0, 0X144C);
    // 0x80800ECC: beq         $a1, $at, L_80800F68
    if (ctx->r5 == ctx->r1) {
        // 0x80800ED0: addiu       $at, $zero, 0x1450
        ctx->r1 = ADD32(0, 0X1450);
            goto L_80800F68;
    }
    // 0x80800ED0: addiu       $at, $zero, 0x1450
    ctx->r1 = ADD32(0, 0X1450);
    // 0x80800ED4: beq         $a1, $at, L_80800F70
    if (ctx->r5 == ctx->r1) {
        // 0x80800ED8: nop
    
            goto L_80800F70;
    }
    // 0x80800ED8: nop

    // 0x80800EDC: b           L_80800F80
    // 0x80800EE0: nop

        goto L_80800F80;
    // 0x80800EE0: nop

L_80800EE4:
    // 0x80800EE4: slti        $at, $a1, 0x144A
    ctx->r1 = SIGNED(ctx->r5) < 0X144A ? 1 : 0;
    // 0x80800EE8: bne         $at, $zero, L_80800F00
    if (ctx->r1 != 0) {
        // 0x80800EEC: addiu       $at, $zero, 0x144A
        ctx->r1 = ADD32(0, 0X144A);
            goto L_80800F00;
    }
    // 0x80800EEC: addiu       $at, $zero, 0x144A
    ctx->r1 = ADD32(0, 0X144A);
    // 0x80800EF0: beq         $a1, $at, L_80800F58
    if (ctx->r5 == ctx->r1) {
        // 0x80800EF4: nop
    
            goto L_80800F58;
    }
    // 0x80800EF4: nop

    // 0x80800EF8: b           L_80800F80
    // 0x80800EFC: nop

        goto L_80800F80;
    // 0x80800EFC: nop

L_80800F00:
    // 0x80800F00: slti        $at, $a1, 0x1410
    ctx->r1 = SIGNED(ctx->r5) < 0X1410 ? 1 : 0;
    // 0x80800F04: bne         $at, $zero, L_80800F20
    if (ctx->r1 != 0) {
        // 0x80800F08: addiu       $t6, $a1, -0x1405
        ctx->r14 = ADD32(ctx->r5, -0X1405);
            goto L_80800F20;
    }
    // 0x80800F08: addiu       $t6, $a1, -0x1405
    ctx->r14 = ADD32(ctx->r5, -0X1405);
    // 0x80800F0C: addiu       $at, $zero, 0x1449
    ctx->r1 = ADD32(0, 0X1449);
    // 0x80800F10: beq         $a1, $at, L_80800F40
    if (ctx->r5 == ctx->r1) {
        // 0x80800F14: nop
    
            goto L_80800F40;
    }
    // 0x80800F14: nop

    // 0x80800F18: b           L_80800F80
    // 0x80800F1C: nop

        goto L_80800F80;
    // 0x80800F1C: nop

L_80800F20:
    // 0x80800F20: sltiu       $at, $t6, 0xB
    ctx->r1 = ctx->r14 < 0XB ? 1 : 0;
    // 0x80800F24: beq         $at, $zero, L_80800F80
    if (ctx->r1 == 0) {
        // 0x80800F28: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800F80;
    }
    // 0x80800F28: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800F2C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(776, 0X1E74) << 16);
    // 0x80800F30: addu        $at, $at, $t6
    gpr jr_addend_80800F38 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800F34: lw          $t6, 0x1E74($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(776, 0X1E74));
    // 0x80800F38: jr          $t6
    // 0x80800F3C: nop

    switch (jr_addend_80800F38 >> 2) {
        case 0: goto L_80800F40; break;
        case 1: goto L_80800F58; break;
        case 2: goto L_80800F80; break;
        case 3: goto L_80800F80; break;
        case 4: goto L_80800F60; break;
        case 5: goto L_80800F80; break;
        case 6: goto L_80800F80; break;
        case 7: goto L_80800F80; break;
        case 8: goto L_80800F80; break;
        case 9: goto L_80800F68; break;
        case 10: goto L_80800F70; break;
        default: switch_error(__func__, 0x80800F38, 0x80801E74);
    }
    // 0x80800F3C: nop

L_80800F40:
    // 0x80800F40: beq         $a2, $zero, L_80800F50
    if (ctx->r6 == 0) {
        // 0x80800F44: addiu       $v1, $zero, 0x28
        ctx->r3 = ADD32(0, 0X28);
            goto L_80800F50;
    }
    // 0x80800F44: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
    // 0x80800F48: b           L_80800F88
    // 0x80800F4C: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
        goto L_80800F88;
    // 0x80800F4C: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_80800F50:
    // 0x80800F50: b           L_80800F88
    // 0x80800F54: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800F88;
    // 0x80800F54: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800F58:
    // 0x80800F58: b           L_80800F88
    // 0x80800F5C: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
        goto L_80800F88;
    // 0x80800F5C: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
L_80800F60:
    // 0x80800F60: b           L_80800F88
    // 0x80800F64: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
        goto L_80800F88;
    // 0x80800F64: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_80800F68:
    // 0x80800F68: b           L_80800F88
    // 0x80800F6C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
        goto L_80800F88;
    // 0x80800F6C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
L_80800F70:
    // 0x80800F70: bne         $a2, $zero, L_80800F80
    if (ctx->r6 != 0) {
        // 0x80800F74: nop
    
            goto L_80800F80;
    }
    // 0x80800F74: nop

    // 0x80800F78: b           L_80800F88
    // 0x80800F7C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
        goto L_80800F88;
    // 0x80800F7C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
L_80800F80:
    // 0x80800F80: jal         0x800D211C
    // 0x80800F84: addiu       $a0, $zero, 0x87
    ctx->r4 = ADD32(0, 0X87);
    func_800D211C(rdram, ctx);
        goto after_0;
    // 0x80800F84: addiu       $a0, $zero, 0x87
    ctx->r4 = ADD32(0, 0X87);
    after_0:
L_80800F88:
    // 0x80800F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F90: jr          $ra
    // 0x80800F94: nop

    return;
    // 0x80800F94: nop

;}
RECOMP_FUNC void func_800F76B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F76B0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F76B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F76B8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F76BC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F76C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F76C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F76C8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F76CC: jal         0x8009AD20
    // 0x800F76D0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009AD20(rdram, ctx);
        goto after_0;
    // 0x800F76D0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F76D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F76D8: jal         0x8009AD14
    // 0x800F76DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8009AD14(rdram, ctx);
        goto after_1;
    // 0x800F76DC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800F76E0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F76E4: jal         0x8009E7C8
    // 0x800F76E8: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_8009E7C8(rdram, ctx);
        goto after_2;
    // 0x800F76E8: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_2:
    // 0x800F76EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F76F0: xori        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 ^ 0X2;
    // 0x800F76F4: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F76F8: jr          $ra
    // 0x800F76FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F76FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _chcactusofstrength_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C38: syscall     211
    recomp_syscall_handler(rdram, ctx, 0x80085C38);
    return;
    // 0x80085C3C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808009C8_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009D4: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808009D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009DC: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x808009E0: bgez        $t8, L_808009F0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808009E4: nop
    
            goto L_808009F0;
    }
    // 0x808009E4: nop

    // 0x808009E8: b           L_80800A2C
    // 0x808009EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A2C;
    // 0x808009EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009F0:
    // 0x808009F0: jal         0x800DA298
    // 0x808009F4: addiu       $a0, $zero, 0xA24
    ctx->r4 = ADD32(0, 0XA24);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808009F4: addiu       $a0, $zero, 0xA24
    ctx->r4 = ADD32(0, 0XA24);
    after_0:
    // 0x808009F8: beq         $v0, $zero, L_80800A28
    if (ctx->r2 == 0) {
        // 0x808009FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A28;
    }
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A00: jal         0x80101FDC
    // 0x80800A04: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800A04: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80800A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A0C: jal         0x80108B04
    // 0x80800A10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x80800A10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800A14: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800A18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800A1C: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x80800A20: b           L_80800A2C
    // 0x80800A24: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
        goto L_80800A2C;
    // 0x80800A24: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_80800A28:
    // 0x80800A28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A2C:
    // 0x80800A2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A38: jr          $ra
    // 0x80800A3C: nop

    return;
    // 0x80800A3C: nop

;}
RECOMP_FUNC void func_8010F270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010F270: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010F274: jr          $ra
    // 0x8010F278: sw          $zero, 0x7210($at)
    MEM_W(0X7210, ctx->r1) = 0;
    return;
    // 0x8010F278: sw          $zero, 0x7210($at)
    MEM_W(0X7210, ctx->r1) = 0;
    // 0x8010F27C: nop

;}
RECOMP_FUNC void _bscrouch_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F68: syscall     36
    recomp_syscall_handler(rdram, ctx, 0x80082F68);
    return;
    // 0x80082F6C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void fxripple_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800218: jal         0x80800094
    // 0x8080021C: nop

    func_80800094_fxripple(rdram, ctx);
        goto after_0;
    // 0x8080021C: nop

    after_0:
    // 0x80800220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800228: jr          $ra
    // 0x8080022C: nop

    return;
    // 0x8080022C: nop

;}
RECOMP_FUNC void func_800AAD80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AAD80: lhu         $t6, 0x10($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X10);
    // 0x800AAD84: lhu         $t8, 0x14($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X14);
    // 0x800AAD88: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800AAD8C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800AAD90: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AAD94: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x800AAD98: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800AAD9C: addiu       $a2, $v0, 0x18
    ctx->r6 = ADD32(ctx->r2, 0X18);
    // 0x800AADA0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800AADA4: addu        $a1, $t9, $a2
    ctx->r5 = ADD32(ctx->r25, ctx->r6);
    // 0x800AADA8: sltu        $at, $a2, $a1
    ctx->r1 = ctx->r6 < ctx->r5 ? 1 : 0;
    // 0x800AADAC: beq         $at, $zero, L_800AADDC
    if (ctx->r1 == 0) {
        // 0x800AADB0: lui         $v0, 0x2
        ctx->r2 = S32(0X2 << 16);
            goto L_800AADDC;
    }
    // 0x800AADB0: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x800AADB4: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x800AADB8: lw          $t0, 0x8($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X8);
L_800AADBC:
    // 0x800AADBC: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x800AADC0: sltu        $at, $a2, $a1
    ctx->r1 = ctx->r6 < ctx->r5 ? 1 : 0;
    // 0x800AADC4: and         $t1, $t0, $v0
    ctx->r9 = ctx->r8 & ctx->r2;
    // 0x800AADC8: beq         $t1, $zero, L_800AADD4
    if (ctx->r9 == 0) {
        // 0x800AADCC: nop
    
            goto L_800AADD4;
    }
    // 0x800AADCC: nop

    // 0x800AADD0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800AADD4:
    // 0x800AADD4: bnel        $at, $zero, L_800AADBC
    if (ctx->r1 != 0) {
        // 0x800AADD8: lw          $t0, 0x8($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X8);
            goto L_800AADBC;
    }
    goto skip_0;
    // 0x800AADD8: lw          $t0, 0x8($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X8);
    skip_0:
L_800AADDC:
    // 0x800AADDC: jr          $ra
    // 0x800AADE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800AADE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800A9F60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9F60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A9F64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A9F68: jal         0x800DA3B8
    // 0x800A9F6C: addiu       $a0, $a0, 0xD1B
    ctx->r4 = ADD32(ctx->r4, 0XD1B);
    func_800DA3B8(rdram, ctx);
        goto after_0;
    // 0x800A9F6C: addiu       $a0, $a0, 0xD1B
    ctx->r4 = ADD32(ctx->r4, 0XD1B);
    after_0:
    // 0x800A9F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A9F74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A9F78: jr          $ra
    // 0x800A9F7C: nop

    return;
    // 0x800A9F7C: nop

;}
RECOMP_FUNC void func_80800544_chfantasycannon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800544: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800548: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080054C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800550: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80800554: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800558: jal         0x80100094
    // 0x8080055C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080055C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800560: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x80800564: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80800568: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8080056C: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80800570: beq         $at, $zero, L_80800890
    if (ctx->r1 == 0) {
        // 0x80800574: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800890;
    }
    // 0x80800574: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800578: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2392, 0XC9C) << 16);
    // 0x8080057C: addu        $at, $at, $t7
    gpr jr_addend_80800584 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800580: lw          $t7, 0xC9C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2392, 0XC9C));
    // 0x80800584: jr          $t7
    // 0x80800588: nop

    switch (jr_addend_80800584 >> 2) {
        case 0: goto L_8080058C; break;
        case 1: goto L_808005D8; break;
        case 2: goto L_808005E8; break;
        case 3: goto L_808006D8; break;
        case 4: goto L_80800890; break;
        case 5: goto L_8080084C; break;
        default: switch_error(__func__, 0x80800584, 0x80800C9C);
    }
    // 0x80800588: nop

L_8080058C:
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: jal         0x8008A4B0
    // 0x80800594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800594: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800598: jal         0x800F54E4
    // 0x8080059C: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x8080059C: nop

    after_2:
    // 0x808005A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005A4: jal         0x800F7F98
    // 0x808005A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_3;
    // 0x808005A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808005AC: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x808005B0: sll         $t0, $t8, 12
    ctx->r8 = S32(ctx->r24 << 12);
    // 0x808005B4: bgezl       $t0, L_80800894
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808005B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800894;
    }
    goto skip_0;
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808005BC: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x808005C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005C4: andi        $t2, $t1, 0xFFF7
    ctx->r10 = ctx->r9 & 0XFFF7;
    // 0x808005C8: jal         0x800856B8
    // 0x808005CC: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    _capod_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808005CC: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    after_4:
    // 0x808005D0: b           L_80800894
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800894;
    // 0x808005D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808005D8:
    // 0x808005D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005E0: b           L_80800890
    // 0x808005E4: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
        goto L_80800890;
    // 0x808005E4: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
L_808005E8:
    // 0x808005E8: jal         0x800DA298
    // 0x808005EC: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x808005EC: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    after_5:
    // 0x808005F0: beq         $v0, $zero, L_80800610
    if (ctx->r2 == 0) {
        // 0x808005F4: addiu       $a0, $zero, 0x40E
        ctx->r4 = ADD32(0, 0X40E);
            goto L_80800610;
    }
    // 0x808005F4: addiu       $a0, $zero, 0x40E
    ctx->r4 = ADD32(0, 0X40E);
    // 0x808005F8: jal         0x80089C30
    // 0x808005FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x808005FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800600: beq         $v0, $zero, L_80800610
    if (ctx->r2 == 0) {
        // 0x80800604: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800610;
    }
    // 0x80800604: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800608: jal         0x8010A624
    // 0x8080060C: nop

    func_8010A624(rdram, ctx);
        goto after_7;
    // 0x8080060C: nop

    after_7:
L_80800610:
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800614: jal         0x8008A4B0
    // 0x80800618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8080061C: jal         0x800F54E4
    // 0x80800620: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x80800620: nop

    after_9:
    // 0x80800624: jal         0x800F5EF8
    // 0x80800628: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_10;
    // 0x80800628: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x8080062C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800630: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x80800634: jal         0x8010FFB0
    // 0x80800638: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    func_8010FFB0(rdram, ctx);
        goto after_11;
    // 0x80800638: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    after_11:
    // 0x8080063C: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x80800640: ori         $a2, $a2, 0x804
    ctx->r6 = ctx->r6 | 0X804;
    // 0x80800644: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800648: jal         0x800856B0
    // 0x8080064C: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    _capod_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x8080064C: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    after_12:
    // 0x80800650: jal         0x800856E0
    // 0x80800654: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_8(rdram, ctx);
        goto after_13;
    // 0x80800654: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80800658: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x8080065C: jal         0x800856A8
    // 0x80800660: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    _capod_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x80800660: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    after_14:
    // 0x80800664: jal         0x80800000
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chfantasycannon(rdram, ctx);
        goto after_15;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080066C: beq         $v0, $zero, L_8080068C
    if (ctx->r2 == 0) {
        // 0x80800670: lw          $a0, 0x84($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X84);
            goto L_8080068C;
    }
    // 0x80800670: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x80800674: jal         0x800EE7F8
    // 0x80800678: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800EE7F8(rdram, ctx);
        goto after_16;
    // 0x80800678: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_16:
    // 0x8080067C: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x80800680: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x80800684: jal         0x800EE7F8
    // 0x80800688: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_17;
    // 0x80800688: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_17:
L_8080068C:
    // 0x8080068C: jal         0x800F54E4
    // 0x80800690: nop

    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x80800690: nop

    after_18:
    // 0x80800694: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800698: jal         0x800F7F98
    // 0x8080069C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_19;
    // 0x8080069C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x808006A0: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x808006A4: ori         $t5, $t4, 0x8
    ctx->r13 = ctx->r12 | 0X8;
    // 0x808006A8: jal         0x800F54E4
    // 0x808006AC: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    func_800F54E4(rdram, ctx);
        goto after_20;
    // 0x808006AC: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    after_20:
    // 0x808006B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006B4: jal         0x800F5A00
    // 0x808006B8: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_800F5A00(rdram, ctx);
        goto after_21;
    // 0x808006B8: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_21:
    // 0x808006BC: jal         0x80015184
    // 0x808006C0: nop

    func_80015184(rdram, ctx);
        goto after_22;
    // 0x808006C0: nop

    after_22:
    // 0x808006C4: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x808006C8: jal         0x80015178
    // 0x808006CC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80015178(rdram, ctx);
        goto after_23;
    // 0x808006CC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_23:
    // 0x808006D0: b           L_80800894
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800894;
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808006D8:
    // 0x808006D8: jal         0x80800000
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chfantasycannon(rdram, ctx);
        goto after_24;
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808006E0: beq         $v0, $zero, L_80800778
    if (ctx->r2 == 0) {
        // 0x808006E4: lui         $at, 0xC448
        ctx->r1 = S32(0XC448 << 16);
            goto L_80800778;
    }
    // 0x808006E4: lui         $at, 0xC448
    ctx->r1 = S32(0XC448 << 16);
    // 0x808006E8: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808006EC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x808006F0: jal         0x800F1DF4
    // 0x808006F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_25;
    // 0x808006F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_25:
    // 0x808006F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808006FC: lui         $a3, 0x449C
    ctx->r7 = S32(0X449C << 16);
    // 0x80800700: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80800704: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800708: jal         0x800EEC30
    // 0x8080070C: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    func_800EEC30(rdram, ctx);
        goto after_26;
    // 0x8080070C: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    after_26:
    // 0x80800710: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800714: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800718: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8080071C: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800720: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800724: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800728: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080072C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800730: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800734: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800738: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8080073C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800740: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800744: jal         0x800EFA4C
    // 0x80800748: nop

    func_800EFA4C(rdram, ctx);
        goto after_27;
    // 0x80800748: nop

    after_27:
    // 0x8080074C: jal         0x800F54E4
    // 0x80800750: nop

    func_800F54E4(rdram, ctx);
        goto after_28;
    // 0x80800750: nop

    after_28:
    // 0x80800754: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800758: jal         0x800F8294
    // 0x8080075C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800F8294(rdram, ctx);
        goto after_29;
    // 0x8080075C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_29:
    // 0x80800760: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2392, 0XCB4) << 16);
    // 0x80800764: lwc1        $f16, 0xCB4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2392, 0XCB4));
    // 0x80800768: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8080076C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800770: b           L_80800824
    // 0x80800774: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
        goto L_80800824;
    // 0x80800774: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
L_80800778:
    // 0x80800778: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080077C: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80800780: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800784: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x80800788: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080078C: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x80800790: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80800794: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800798: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8080079C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808007A0: jal         0x800EFA4C
    // 0x808007A4: nop

    func_800EFA4C(rdram, ctx);
        goto after_30;
    // 0x808007A4: nop

    after_30:
    // 0x808007A8: jal         0x800F54E4
    // 0x808007AC: nop

    func_800F54E4(rdram, ctx);
        goto after_31;
    // 0x808007AC: nop

    after_31:
    // 0x808007B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808007B4: jal         0x800F8294
    // 0x808007B8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F8294(rdram, ctx);
        goto after_32;
    // 0x808007B8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_32:
    // 0x808007BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2392, 0XCB8) << 16);
    // 0x808007C0: lwc1        $f0, 0xCB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2392, 0XCB8));
    // 0x808007C4: lui         $at, 0xC448
    ctx->r1 = S32(0XC448 << 16);
    // 0x808007C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808007CC: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808007D0: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808007D4: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x808007D8: addiu       $t7, $s0, 0x18
    ctx->r15 = ADD32(ctx->r16, 0X18);
    // 0x808007DC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808007E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808007E4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808007E8: nop

    // 0x808007EC: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x808007F0: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x808007F4: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x808007F8: nop

    // 0x808007FC: bc1f        L_8080081C
    if (!c1cs) {
        // 0x80800800: nop
    
            goto L_8080081C;
    }
    // 0x80800800: nop

    // 0x80800804: jal         0x8002DCA0
    // 0x80800808: nop

    sqrtf_recomp(rdram, ctx);
        goto after_33;
    // 0x80800808: nop

    after_33:
    // 0x8080080C: addiu       $t6, $s0, 0x18
    ctx->r14 = ADD32(ctx->r16, 0X18);
    // 0x80800810: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80800814: b           L_80800824
    // 0x80800818: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_80800824;
    // 0x80800818: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_8080081C:
    // 0x8080081C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800820: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800824:
    // 0x80800824: jal         0x800F54E4
    // 0x80800828: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    func_800F54E4(rdram, ctx);
        goto after_34;
    // 0x80800828: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    after_34:
    // 0x8080082C: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800830: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800834: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800838: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8080083C: jal         0x800F78EC
    // 0x80800840: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    func_800F78EC(rdram, ctx);
        goto after_35;
    // 0x80800840: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    after_35:
    // 0x80800844: b           L_80800894
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800894;
    // 0x80800848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080084C:
    // 0x8080084C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800850: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800854: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80800858: jal         0x80015178
    // 0x8080085C: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
    func_80015178(rdram, ctx);
        goto after_36;
    // 0x8080085C: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
    after_36:
    // 0x80800860: jal         0x80800028
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800028_chfantasycannon(rdram, ctx);
        goto after_37;
    // 0x80800864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800868: jal         0x800DA298
    // 0x8080086C: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    func_800DA298(rdram, ctx);
        goto after_38;
    // 0x8080086C: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    after_38:
    // 0x80800870: beq         $v0, $zero, L_80800890
    if (ctx->r2 == 0) {
        // 0x80800874: addiu       $a0, $zero, 0x40E
        ctx->r4 = ADD32(0, 0X40E);
            goto L_80800890;
    }
    // 0x80800874: addiu       $a0, $zero, 0x40E
    ctx->r4 = ADD32(0, 0X40E);
    // 0x80800878: jal         0x80089C30
    // 0x8080087C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_39;
    // 0x8080087C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_39:
    // 0x80800880: beq         $v0, $zero, L_80800890
    if (ctx->r2 == 0) {
        // 0x80800884: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800890;
    }
    // 0x80800884: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800888: jal         0x8010A63C
    // 0x8080088C: nop

    func_8010A63C(rdram, ctx);
        goto after_40;
    // 0x8080088C: nop

    after_40:
L_80800890:
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800894:
    // 0x80800894: jal         0x80102424
    // 0x80800898: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    func_80102424(rdram, ctx);
        goto after_41;
    // 0x80800898: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    after_41:
    // 0x8080089C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008A4: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x808008A8: jr          $ra
    // 0x808008AC: nop

    return;
    // 0x808008AC: nop

;}
RECOMP_FUNC void func_8002C5A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C5A0: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8002C5A4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8002C5A8: sh          $a1, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r5;
    // 0x8002C5AC: jr          $ra
    // 0x8002C5B0: nop

    return;
    // 0x8002C5B0: nop

;}
RECOMP_FUNC void bsbegghead_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080027C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800280: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800284: jal         0x80098140
    // 0x80800288: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    bainput_enable(rdram, ctx);
        goto after_0;
    // 0x80800288: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8080028C: jal         0x8009BC6C
    // 0x80800290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_gravity(rdram, ctx);
        goto after_1;
    // 0x80800290: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800294: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800298: jal         0x800A0CF4
    // 0x8080029C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_2;
    // 0x8080029C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808002A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002A8: jr          $ra
    // 0x808002AC: nop

    return;
    // 0x808002AC: nop

;}
RECOMP_FUNC void idtwinkle_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C4: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x808008C8: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x808008CC: lh          $t8, 0x28($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X28);
    // 0x808008D0: lw          $t7, 0x2C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2C);
    // 0x808008D4: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x808008D8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x808008DC: jr          $ra
    // 0x808008E0: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    return;
    // 0x808008E0: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x808008E4: nop

    // 0x808008E8: nop

    // 0x808008EC: nop

;}
RECOMP_FUNC void suegg_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001DC: jal         0x808001F4
    // 0x808001E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    suegg_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808001E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808001E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001EC: jr          $ra
    // 0x808001F0: nop

    return;
    // 0x808001F0: nop

;}
RECOMP_FUNC void func_808005FC_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800600: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800604: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800608: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080060C: jal         0x80100094
    // 0x80800610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800614: lbu         $t6, 0x26($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X26);
    // 0x80800618: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x8080061C: beq         $at, $zero, L_80800714
    if (ctx->r1 == 0) {
        // 0x80800620: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800714;
    }
    // 0x80800620: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800624: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X3E60) << 16);
    // 0x80800628: addu        $at, $at, $t6
    gpr jr_addend_80800630 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080062C: lw          $t6, 0x3E60($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1692, 0X3E60));
    // 0x80800630: jr          $t6
    // 0x80800634: nop

    switch (jr_addend_80800630 >> 2) {
        case 0: goto L_80800638; break;
        case 1: goto L_8080067C; break;
        case 2: goto L_80800698; break;
        case 3: goto L_808006B4; break;
        case 4: goto L_808006D0; break;
        case 5: goto L_808006EC; break;
        case 6: goto L_80800708; break;
        default: switch_error(__func__, 0x80800630, 0x80803E60);
    }
    // 0x80800634: nop

L_80800638:
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080063C: jal         0x808012A4
    // 0x80800640: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_1;
    // 0x80800640: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800648: jal         0x808009DC
    // 0x8080064C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808009DC_chflysaucer(rdram, ctx);
        goto after_2;
    // 0x8080064C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800654: jal         0x8080003C
    // 0x80800658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8080003C_chflysaucer(rdram, ctx);
        goto after_3;
    // 0x80800658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080065C: jal         0x800D395C
    // 0x80800660: nop

    func_800D395C(rdram, ctx);
        goto after_4;
    // 0x80800660: nop

    after_4:
    // 0x80800664: bnel        $v0, $zero, L_80800718
    if (ctx->r2 != 0) {
        // 0x80800668: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800718;
    }
    goto skip_0;
    // 0x80800668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080066C: jal         0x80800514
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800514_chflysaucer(rdram, ctx);
        goto after_5;
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800674: b           L_80800718
    // 0x80800678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800718;
    // 0x80800678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080067C:
    // 0x8080067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800680: jal         0x8080003C
    // 0x80800684: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080003C_chflysaucer(rdram, ctx);
        goto after_6;
    // 0x80800684: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80800688: jal         0x80800514
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800514_chflysaucer(rdram, ctx);
        goto after_7;
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800690: b           L_80800718
    // 0x80800694: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800718;
    // 0x80800694: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800698:
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080069C: jal         0x8080003C
    // 0x808006A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080003C_chflysaucer(rdram, ctx);
        goto after_8;
    // 0x808006A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x808006A4: jal         0x80800514
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800514_chflysaucer(rdram, ctx);
        goto after_9;
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808006AC: b           L_80800718
    // 0x808006B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800718;
    // 0x808006B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006B4:
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B8: jal         0x8080003C
    // 0x808006BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080003C_chflysaucer(rdram, ctx);
        goto after_10;
    // 0x808006BC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x808006C0: jal         0x80800514
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800514_chflysaucer(rdram, ctx);
        goto after_11;
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808006C8: b           L_80800718
    // 0x808006CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800718;
    // 0x808006CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006D0:
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D4: jal         0x8080003C
    // 0x808006D8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080003C_chflysaucer(rdram, ctx);
        goto after_12;
    // 0x808006D8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_12:
    // 0x808006DC: jal         0x80800514
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800514_chflysaucer(rdram, ctx);
        goto after_13;
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808006E4: b           L_80800718
    // 0x808006E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800718;
    // 0x808006E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006EC:
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F0: jal         0x8080003C
    // 0x808006F4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8080003C_chflysaucer(rdram, ctx);
        goto after_14;
    // 0x808006F4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_14:
    // 0x808006F8: jal         0x80800514
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800514_chflysaucer(rdram, ctx);
        goto after_15;
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800700: b           L_80800718
    // 0x80800704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800718;
    // 0x80800704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800708:
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080070C: jal         0x8080003C
    // 0x80800710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080003C_chflysaucer(rdram, ctx);
        goto after_16;
    // 0x80800710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
L_80800714:
    // 0x80800714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800718:
    // 0x80800718: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080071C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800720: jr          $ra
    // 0x80800724: nop

    return;
    // 0x80800724: nop

;}
RECOMP_FUNC void func_800E3CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3CE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3CEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3CF0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3CF4: jal         0x800CAF34
    // 0x800E3CF8: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CAF34(rdram, ctx);
        goto after_0;
    // 0x800E3CF8: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3D00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3D04: jr          $ra
    // 0x800E3D08: nop

    return;
    // 0x800E3D08: nop

;}
RECOMP_FUNC void func_800EE88C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE88C: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x800EE890: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800EE894: nop

    // 0x800EE898: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EE89C: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800EE8A0: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x800EE8A4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800EE8A8: nop

    // 0x800EE8AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800EE8B0: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x800EE8B4: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x800EE8B8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800EE8BC: nop

    // 0x800EE8C0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EE8C4: jr          $ra
    // 0x800EE8C8: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x800EE8C8: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_800EDAF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDAF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EDAF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EDAFC: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x800EDB00: beql        $a1, $zero, L_800EDB14
    if (ctx->r5 == 0) {
        // 0x800EDB04: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EDB14;
    }
    goto skip_0;
    // 0x800EDB04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800EDB08: jal         0x800C2FDC
    // 0x800EDB0C: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x800EDB0C: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    after_0:
    // 0x800EDB10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EDB14:
    // 0x800EDB14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EDB18: jr          $ra
    // 0x800EDB1C: nop

    return;
    // 0x800EDB1C: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800894E0: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x800894E0);
    return;
    // 0x800894E4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bskazstilt_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083660: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083660);
    return;
    // 0x80083664: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80802538_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802538: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080253C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802540: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802544: jal         0x80100094
    // 0x80802548: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802548: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080254C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802550: lbu         $t6, 0x57($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X57);
    // 0x80802554: bne         $t6, $zero, L_8080257C
    if (ctx->r14 != 0) {
        // 0x80802558: nop
    
            goto L_8080257C;
    }
    // 0x80802558: nop

    // 0x8080255C: jal         0x800F54E4
    // 0x80802560: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80802560: nop

    after_1:
    // 0x80802564: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802568: jal         0x800F4AF4
    // 0x8080256C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_800F4AF4(rdram, ctx);
        goto after_2;
    // 0x8080256C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_2:
    // 0x80802570: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80802574: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80802578: sb          $t7, 0x57($t8)
    MEM_B(0X57, ctx->r24) = ctx->r15;
L_8080257C:
    // 0x8080257C: jal         0x808025DC
    // 0x80802580: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808025DC_chboilerboss(rdram, ctx);
        goto after_3;
    // 0x80802580: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80802584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802588: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080258C: jr          $ra
    // 0x80802590: nop

    return;
    // 0x80802590: nop

;}
RECOMP_FUNC void _gcegg_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883F0: syscall     680
    recomp_syscall_handler(rdram, ctx, 0x800883F0);
    return;
    // 0x800883F4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085638: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085638);
    return;
    // 0x8008563C: addi        $t0, $zero, 0x5C
    ctx->r8 = ADD32(0, 0X5C);
;}
RECOMP_FUNC void _bsrest_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800839C0: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x800839C0);
    return;
    // 0x800839C4: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_808000E4_chstatictorch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E4: jr          $ra
    // 0x808000E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808000E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void chpotogoldgame_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808019E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808019E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808019EC: jal         0x80106790
    // 0x808019F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808019F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808019F4: lw          $v1, 0x6C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X6C);
    // 0x808019F8: addiu       $at, $zero, 0x15A
    ctx->r1 = ADD32(0, 0X15A);
    // 0x808019FC: sll         $t6, $v1, 11
    ctx->r14 = S32(ctx->r3 << 11);
    // 0x80801A00: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x80801A04: beq         $t7, $at, L_80801A2C
    if (ctx->r15 == ctx->r1) {
        // 0x80801A08: addiu       $at, $zero, 0x15B
        ctx->r1 = ADD32(0, 0X15B);
            goto L_80801A2C;
    }
    // 0x80801A08: addiu       $at, $zero, 0x15B
    ctx->r1 = ADD32(0, 0X15B);
    // 0x80801A0C: beq         $t7, $at, L_80801A34
    if (ctx->r15 == ctx->r1) {
        // 0x80801A10: addiu       $at, $zero, 0x15C
        ctx->r1 = ADD32(0, 0X15C);
            goto L_80801A34;
    }
    // 0x80801A10: addiu       $at, $zero, 0x15C
    ctx->r1 = ADD32(0, 0X15C);
    // 0x80801A14: beq         $t7, $at, L_80801A3C
    if (ctx->r15 == ctx->r1) {
        // 0x80801A18: addiu       $at, $zero, 0x15D
        ctx->r1 = ADD32(0, 0X15D);
            goto L_80801A3C;
    }
    // 0x80801A18: addiu       $at, $zero, 0x15D
    ctx->r1 = ADD32(0, 0X15D);
    // 0x80801A1C: beq         $t7, $at, L_80801A44
    if (ctx->r15 == ctx->r1) {
        // 0x80801A20: addiu       $a1, $zero, 0x9F9
        ctx->r5 = ADD32(0, 0X9F9);
            goto L_80801A44;
    }
    // 0x80801A20: addiu       $a1, $zero, 0x9F9
    ctx->r5 = ADD32(0, 0X9F9);
    // 0x80801A24: b           L_80801A70
    // 0x80801A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801A70;
    // 0x80801A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801A2C:
    // 0x80801A2C: b           L_80801A44
    // 0x80801A30: addiu       $a1, $zero, 0x9F6
    ctx->r5 = ADD32(0, 0X9F6);
        goto L_80801A44;
    // 0x80801A30: addiu       $a1, $zero, 0x9F6
    ctx->r5 = ADD32(0, 0X9F6);
L_80801A34:
    // 0x80801A34: b           L_80801A44
    // 0x80801A38: addiu       $a1, $zero, 0x9F7
    ctx->r5 = ADD32(0, 0X9F7);
        goto L_80801A44;
    // 0x80801A38: addiu       $a1, $zero, 0x9F7
    ctx->r5 = ADD32(0, 0X9F7);
L_80801A3C:
    // 0x80801A3C: b           L_80801A44
    // 0x80801A40: addiu       $a1, $zero, 0x9F8
    ctx->r5 = ADD32(0, 0X9F8);
        goto L_80801A44;
    // 0x80801A40: addiu       $a1, $zero, 0x9F8
    ctx->r5 = ADD32(0, 0X9F8);
L_80801A44:
    // 0x80801A44: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80801A48: jal         0x800DA298
    // 0x80801A4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80801A4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80801A50: bne         $v0, $zero, L_80801A6C
    if (ctx->r2 != 0) {
        // 0x80801A54: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80801A6C;
    }
    // 0x80801A54: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A58: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80801A5C: jal         0x800FC6B0
    // 0x80801A60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800FC6B0(rdram, ctx);
        goto after_2;
    // 0x80801A60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80801A64: jal         0x800DA544
    // 0x80801A68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80801A68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
L_80801A6C:
    // 0x80801A6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801A70:
    // 0x80801A70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801A74: jr          $ra
    // 0x80801A78: nop

    return;
    // 0x80801A78: nop

;}
RECOMP_FUNC void _sujiggy_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A718: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A718);
    return;
    // 0x8008A71C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void bsjump_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E54: jr          $ra
    // 0x80800E58: lw          $v0, 0x160($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X160);
    return;
    // 0x80800E58: lw          $v0, 0x160($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X160);
;}
RECOMP_FUNC void glgamedata_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800154: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800158: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080015C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800160: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800164: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800168: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080016C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800170: jal         0x808004BC
    // 0x80800174: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    glgamedata_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x80800174: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_0:
    // 0x80800178: jal         0x80800084
    // 0x8080017C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80800084_glgamedata(rdram, ctx);
        goto after_1;
    // 0x8080017C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x80800180: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800184: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800188: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
    // 0x8080018C: addiu       $s1, $sp, 0x28
    ctx->r17 = ADD32(ctx->r29, 0X28);
    // 0x80800190: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80800194:
    // 0x80800194: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800198: jal         0x80800098
    // 0x8080019C: andi        $a2, $s0, 0xFF
    ctx->r6 = ctx->r16 & 0XFF;
    func_80800098_glgamedata(rdram, ctx);
        goto after_2;
    // 0x8080019C: andi        $a2, $s0, 0xFF
    ctx->r6 = ctx->r16 & 0XFF;
    after_2:
    // 0x808001A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808001A4: bnel        $s0, $s2, L_80800194
    if (ctx->r16 != ctx->r18) {
        // 0x808001A8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800194;
    }
    goto skip_0;
    // 0x808001A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x808001AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808001B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808001B4: jal         0x80800098
    // 0x808001B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800098_glgamedata(rdram, ctx);
        goto after_3;
    // 0x808001B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x808001BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808001C0: jal         0x80088708
    // 0x808001C4: addiu       $a1, $zero, 0x1C0
    ctx->r5 = ADD32(0, 0X1C0);
    _glcrc_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x808001C4: addiu       $a1, $zero, 0x1C0
    ctx->r5 = ADD32(0, 0X1C0);
    after_4:
    // 0x808001C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808001D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808001D4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808001D8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808001DC: jr          $ra
    // 0x808001E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808001E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_801009C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801009C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801009C8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801009CC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801009D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801009D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801009D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801009DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801009E0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801009E4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801009E8: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
L_801009EC:
    // 0x801009EC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801009F0: beql        $a0, $zero, L_80100A04
    if (ctx->r4 == 0) {
        // 0x801009F4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80100A04;
    }
    goto skip_0;
    // 0x801009F4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x801009F8: jal         0x800B23E0
    // 0x801009FC: nop

    func_800B23E0(rdram, ctx);
        goto after_0;
    // 0x801009FC: nop

    after_0:
    // 0x80100A00: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80100A04:
    // 0x80100A04: bne         $s0, $s2, L_801009EC
    if (ctx->r16 != ctx->r18) {
        // 0x80100A08: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_801009EC;
    }
    // 0x80100A08: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80100A0C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80100A10: lbu         $v0, 0x8($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X8);
    // 0x80100A14: beql        $v0, $zero, L_80100A28
    if (ctx->r2 == 0) {
        // 0x80100A18: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_80100A28;
    }
    goto skip_1;
    // 0x80100A18: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80100A1C: jal         0x80100938
    // 0x80100A20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80100938(rdram, ctx);
        goto after_1;
    // 0x80100A20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80100A24: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
L_80100A28:
    // 0x80100A28: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80100A2C: addiu       $s0, $s0, 0x5A60
    ctx->r16 = ADD32(ctx->r16, 0X5A60);
    // 0x80100A30: sb          $zero, 0x9($t7)
    MEM_B(0X9, ctx->r15) = 0;
    // 0x80100A34: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80100A38: jal         0x800B32C0
    // 0x80100A3C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    freelist_erase(rdram, ctx);
        goto after_2;
    // 0x80100A3C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x80100A40: jal         0x800B3204
    // 0x80100A44: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    freelist_used_count(rdram, ctx);
        goto after_3;
    // 0x80100A44: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80100A48: bnel        $v0, $zero, L_80100A60
    if (ctx->r2 != 0) {
        // 0x80100A4C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80100A60;
    }
    goto skip_2;
    // 0x80100A4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80100A50: jal         0x800B3248
    // 0x80100A54: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    freelist_free(rdram, ctx);
        goto after_4;
    // 0x80100A54: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x80100A58: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80100A5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80100A60:
    // 0x80100A60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80100A64: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80100A68: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80100A6C: jr          $ra
    // 0x80100A70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80100A70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800040_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800048: jal         0x80100094
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800050: lbu         $t6, 0x14($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X14);
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800058: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4CB4) << 16);
    // 0x8080005C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800060: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800064: lwc1        $f0, 0x4CB4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4CB4));
    // 0x80800068: jr          $ra
    // 0x8080006C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8080006C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800AE0_chlagoonfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AE4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AEC: bne         $a1, $at, L_80800B20
    if (ctx->r5 != ctx->r1) {
        // 0x80800AF0: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800B20;
    }
    // 0x80800AF0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800AF4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800AF8: lbu         $t6, 0x762C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X762C);
    // 0x80800AFC: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80800B00: bnel        $t6, $at, L_80800B2C
    if (ctx->r14 != ctx->r1) {
        // 0x80800B04: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800B2C;
    }
    goto skip_0;
    // 0x80800B04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800B08: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80800B0C: addiu       $a1, $zero, 0x698
    ctx->r5 = ADD32(0, 0X698);
    // 0x80800B10: jal         0x80103140
    // 0x80800B14: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x80800B14: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    after_0:
    // 0x80800B18: b           L_80800B2C
    // 0x80800B1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B2C;
    // 0x80800B1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B20:
    // 0x80800B20: b           L_80800B2C
    // 0x80800B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B2C;
    // 0x80800B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800B28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B2C:
    // 0x80800B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B34: jr          $ra
    // 0x80800B38: nop

    return;
    // 0x80800B38: nop

;}
RECOMP_FUNC void _idscroll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088DA8: syscall     740
    recomp_syscall_handler(rdram, ctx, 0x80088DA8);
    return;
    // 0x80088DAC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808002C8_chquizremotectrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002D4: jal         0x8008A7C0
    // 0x808002D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _suquiz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808002D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808002DC: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808002E0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808002E4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808002E8: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x808002EC: beq         $at, $zero, L_80800384
    if (ctx->r1 == 0) {
        // 0x808002F0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800384;
    }
    // 0x808002F0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808002F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1788, 0X620) << 16);
    // 0x808002F8: addu        $at, $at, $t8
    gpr jr_addend_80800300 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808002FC: lw          $t8, 0x620($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1788, 0X620));
    // 0x80800300: jr          $t8
    // 0x80800304: nop

    switch (jr_addend_80800300 >> 2) {
        case 0: goto L_80800308; break;
        case 1: goto L_80800328; break;
        case 2: goto L_80800358; break;
        case 3: goto L_80800378; break;
        case 4: goto L_80800384; break;
        default: switch_error(__func__, 0x80800300, 0x80800620);
    }
    // 0x80800304: nop

L_80800308:
    // 0x80800308: jal         0x800D90A4
    // 0x8080030C: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x8080030C: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    after_1:
    // 0x80800310: beq         $v0, $zero, L_80800384
    if (ctx->r2 == 0) {
        // 0x80800314: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800384;
    }
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: jal         0x808001BC
    // 0x8080031C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808001BC_chquizremotectrl(rdram, ctx);
        goto after_2;
    // 0x8080031C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800320: b           L_80800384
    // 0x80800324: nop

        goto L_80800384;
    // 0x80800324: nop

L_80800328:
    // 0x80800328: jal         0x800D90A4
    // 0x8080032C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_3;
    // 0x8080032C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_3:
    // 0x80800330: bnel        $v0, $zero, L_80800348
    if (ctx->r2 != 0) {
        // 0x80800334: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800348;
    }
    goto skip_0;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800338: jal         0x8008A7E0
    // 0x8080033C: nop

    _suquiz_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x8080033C: nop

    after_4:
    // 0x80800340: beq         $v0, $zero, L_80800384
    if (ctx->r2 == 0) {
        // 0x80800344: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800384;
    }
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800348:
    // 0x80800348: jal         0x808001BC
    // 0x8080034C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808001BC_chquizremotectrl(rdram, ctx);
        goto after_5;
    // 0x8080034C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800350: b           L_80800384
    // 0x80800354: nop

        goto L_80800384;
    // 0x80800354: nop

L_80800358:
    // 0x80800358: jal         0x800D90A4
    // 0x8080035C: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    func_800D90A4(rdram, ctx);
        goto after_6;
    // 0x8080035C: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    after_6:
    // 0x80800360: beq         $v0, $zero, L_80800384
    if (ctx->r2 == 0) {
        // 0x80800364: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800384;
    }
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800368: jal         0x808001BC
    // 0x8080036C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808001BC_chquizremotectrl(rdram, ctx);
        goto after_7;
    // 0x8080036C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x80800370: b           L_80800384
    // 0x80800374: nop

        goto L_80800384;
    // 0x80800374: nop

L_80800378:
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080037C: jal         0x808001BC
    // 0x80800380: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808001BC_chquizremotectrl(rdram, ctx);
        goto after_8;
    // 0x80800380: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_8:
L_80800384:
    // 0x80800384: jal         0x80800068
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800068_chquizremotectrl(rdram, ctx);
        goto after_9;
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080038C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800390: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800394: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800398: jr          $ra
    // 0x8080039C: nop

    return;
    // 0x8080039C: nop

;}
RECOMP_FUNC void func_80800B14_chdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B14: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800B18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B20: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800B24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800B28: jal         0x80100094
    // 0x80800B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B30: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x80800B34: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80800B38: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800B3C: srl         $t6, $a0, 10
    ctx->r14 = S32(U32(ctx->r4) >> 10);
    // 0x80800B40: andi        $t7, $v1, 0x4
    ctx->r15 = ctx->r3 & 0X4;
    // 0x80800B44: beq         $t7, $zero, L_80800B54
    if (ctx->r15 == 0) {
        // 0x80800B48: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_80800B54;
    }
    // 0x80800B48: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80800B4C: b           L_80800B58
    // 0x80800B50: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80800B58;
    // 0x80800B50: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80800B54:
    // 0x80800B54: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80800B58:
    // 0x80800B58: andi        $t8, $v1, 0x8
    ctx->r24 = ctx->r3 & 0X8;
    // 0x80800B5C: beq         $t8, $zero, L_80800B6C
    if (ctx->r24 == 0) {
        // 0x80800B60: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80800B6C;
    }
    // 0x80800B60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B64: b           L_80800B6C
    // 0x80800B68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80800B6C;
    // 0x80800B68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80800B6C:
    // 0x80800B6C: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80800B70: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800B74: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800B78: sll         $t2, $t9, 6
    ctx->r10 = S32(ctx->r25 << 6);
    // 0x80800B7C: bgezl       $t2, L_80800C44
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800B80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C44;
    }
    goto skip_0;
    // 0x80800B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800B84: beq         $a0, $at, L_80800BA0
    if (ctx->r4 == ctx->r1) {
        // 0x80800B88: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_80800BA0;
    }
    // 0x80800B88: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800B8C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800B90: beq         $a0, $at, L_80800BE0
    if (ctx->r4 == ctx->r1) {
        // 0x80800B94: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80800BE0;
    }
    // 0x80800B94: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800B98: b           L_80800C34
    // 0x80800B9C: lbu         $t6, 0x8($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X8);
        goto L_80800C34;
    // 0x80800B9C: lbu         $t6, 0x8($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X8);
L_80800BA0:
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA4: jal         0x80101FDC
    // 0x80800BA8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800BA8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB0: jal         0x80800FC0
    // 0x80800BB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800FC0_chdoor(rdram, ctx);
        goto after_2;
    // 0x80800BB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800BB8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BBC: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800BC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800BC4: lh          $t3, 0xA($a3)
    ctx->r11 = MEM_H(ctx->r7, 0XA);
    // 0x80800BC8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80800BCC: nop

    // 0x80800BD0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800BD4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800BD8: b           L_80800C30
    // 0x80800BDC: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80800C30;
    // 0x80800BDC: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_80800BE0:
    // 0x80800BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BE4: jal         0x80101FDC
    // 0x80800BE8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800BE8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_3:
    // 0x80800BEC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800BF8: lh          $t4, 0xC($a3)
    ctx->r12 = MEM_H(ctx->r7, 0XC);
    // 0x80800BFC: bnel        $t4, $zero, L_80800C14
    if (ctx->r12 != 0) {
        // 0x80800C00: lh          $t5, 0xA($a3)
        ctx->r13 = MEM_H(ctx->r7, 0XA);
            goto L_80800C14;
    }
    goto skip_1;
    // 0x80800C00: lh          $t5, 0xA($a3)
    ctx->r13 = MEM_H(ctx->r7, 0XA);
    skip_1:
    // 0x80800C04: jal         0x80800FC0
    // 0x80800C08: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80800FC0_chdoor(rdram, ctx);
        goto after_4;
    // 0x80800C08: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_4:
    // 0x80800C0C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C10: lh          $t5, 0xA($a3)
    ctx->r13 = MEM_H(ctx->r7, 0XA);
L_80800C14:
    // 0x80800C14: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800C18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C1C: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80800C20: nop

    // 0x80800C24: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800C28: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800C2C: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800C30:
    // 0x80800C30: lbu         $t6, 0x8($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X8);
L_80800C34:
    // 0x80800C34: andi        $t7, $t6, 0xFFFD
    ctx->r15 = ctx->r14 & 0XFFFD;
    // 0x80800C38: b           L_80800FAC
    // 0x80800C3C: sb          $t7, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r15;
        goto L_80800FAC;
    // 0x80800C3C: sb          $t7, 0x8($a3)
    MEM_B(0X8, ctx->r7) = ctx->r15;
    // 0x80800C40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800C44:
    // 0x80800C44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800C48: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800C4C: jal         0x80101FDC
    // 0x80800C50: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800C50: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_5:
    // 0x80800C54: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80800C58: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800C5C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800C60: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80800C64: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x80800C68: beq         $at, $zero, L_80800FAC
    if (ctx->r1 == 0) {
        // 0x80800C6C: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_80800FAC;
    }
    // 0x80800C6C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800C70: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800C74: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1148, 0X158C) << 16);
    // 0x80800C78: addu        $at, $at, $t9
    gpr jr_addend_80800C80 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800C7C: lw          $t9, 0x158C($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1148, 0X158C));
    // 0x80800C80: jr          $t9
    // 0x80800C84: nop

    switch (jr_addend_80800C80 >> 2) {
        case 0: goto L_80800C88; break;
        case 1: goto L_80800D14; break;
        case 2: goto L_80800D5C; break;
        case 3: goto L_80800DE4; break;
        case 4: goto L_80800E6C; break;
        case 5: goto L_80800EB4; break;
        case 6: goto L_80800F6C; break;
        case 7: goto L_80800F90; break;
        default: switch_error(__func__, 0x80800C80, 0x8080158C);
    }
    // 0x80800C84: nop

L_80800C88:
    // 0x80800C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C8C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800C90: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800C94: jal         0x80089D40
    // 0x80800C98: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800C98: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_6:
    // 0x80800C9C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800CA0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CA8: jal         0x80103110
    // 0x80800CAC: or          $a1, $t0, $a2
    ctx->r5 = ctx->r8 | ctx->r6;
    func_80103110(rdram, ctx);
        goto after_7;
    // 0x80800CAC: or          $a1, $t0, $a2
    ctx->r5 = ctx->r8 | ctx->r6;
    after_7:
    // 0x80800CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CB4: jal         0x80801330
    // 0x80800CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801330_chdoor(rdram, ctx);
        goto after_8;
    // 0x80800CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800CBC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800CC0: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x80800CC4: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800CC8: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80800CCC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800CD0: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800CD4: andi        $t2, $t1, 0x100
    ctx->r10 = ctx->r9 & 0X100;
    // 0x80800CD8: beql        $t2, $zero, L_80800FB0
    if (ctx->r10 == 0) {
        // 0x80800CDC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800FB0;
    }
    goto skip_2;
    // 0x80800CDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800CE0: jal         0x800E1610
    // 0x80800CE4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    func_800E1610(rdram, ctx);
        goto after_9;
    // 0x80800CE4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x80800CE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CEC: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800CF0: jal         0x800E148C
    // 0x80800CF4: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    func_800E148C(rdram, ctx);
        goto after_10;
    // 0x80800CF4: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    after_10:
    // 0x80800CF8: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80800CFC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800D00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800D04: jal         0x80018820
    // 0x80800D08: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80018820(rdram, ctx);
        goto after_11;
    // 0x80800D08: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_11:
    // 0x80800D0C: b           L_80800FB0
    // 0x80800D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FB0;
    // 0x80800D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D14:
    // 0x80800D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D1C: jal         0x80800FC0
    // 0x80800D20: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80800FC0_chdoor(rdram, ctx);
        goto after_12;
    // 0x80800D20: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_12:
    // 0x80800D24: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D28: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800D2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800D30: lh          $t3, 0xC($a3)
    ctx->r11 = MEM_H(ctx->r7, 0XC);
    // 0x80800D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800D3C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80800D40: nop

    // 0x80800D44: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800D48: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800D4C: jal         0x80103110
    // 0x80800D50: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    func_80103110(rdram, ctx);
        goto after_13;
    // 0x80800D50: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    after_13:
    // 0x80800D54: b           L_80800FB0
    // 0x80800D58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FB0;
    // 0x80800D58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D5C:
    // 0x80800D5C: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80800D60: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80800D64: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x80800D68: beql        $t5, $zero, L_80800D80
    if (ctx->r13 == 0) {
        // 0x80800D6C: lh          $t6, 0xC($a3)
        ctx->r14 = MEM_H(ctx->r7, 0XC);
            goto L_80800D80;
    }
    goto skip_3;
    // 0x80800D6C: lh          $t6, 0xC($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XC);
    skip_3:
    // 0x80800D70: jal         0x800FC660
    // 0x80800D74: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800FC660(rdram, ctx);
        goto after_14;
    // 0x80800D74: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_14:
    // 0x80800D78: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D7C: lh          $t6, 0xC($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XC);
L_80800D80:
    // 0x80800D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D88: bnel        $t6, $zero, L_80800DA0
    if (ctx->r14 != 0) {
        // 0x80800D8C: lh          $t7, 0xA($a3)
        ctx->r15 = MEM_H(ctx->r7, 0XA);
            goto L_80800DA0;
    }
    goto skip_4;
    // 0x80800D8C: lh          $t7, 0xA($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XA);
    skip_4:
    // 0x80800D90: jal         0x80800FC0
    // 0x80800D94: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80800FC0_chdoor(rdram, ctx);
        goto after_15;
    // 0x80800D94: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_15:
    // 0x80800D98: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D9C: lh          $t7, 0xA($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XA);
L_80800DA0:
    // 0x80800DA0: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800DA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800DA8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800DB4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800DB8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800DBC: jal         0x808005E4
    // 0x80800DC0: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    func_808005E4_chdoor(rdram, ctx);
        goto after_16;
    // 0x80800DC0: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    after_16:
    // 0x80800DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DC8: jal         0x80103110
    // 0x80800DCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_17;
    // 0x80800DCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DD4: jal         0x80801330
    // 0x80800DD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801330_chdoor(rdram, ctx);
        goto after_18;
    // 0x80800DD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80800DDC: b           L_80800FB0
    // 0x80800DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FB0;
    // 0x80800DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800DE4:
    // 0x80800DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DE8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800DEC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800DF0: jal         0x80089D40
    // 0x80800DF4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_19;
    // 0x80800DF4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_19:
    // 0x80800DF8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800DFC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E04: jal         0x80103110
    // 0x80800E08: or          $a1, $t0, $a2
    ctx->r5 = ctx->r8 | ctx->r6;
    func_80103110(rdram, ctx);
        goto after_20;
    // 0x80800E08: or          $a1, $t0, $a2
    ctx->r5 = ctx->r8 | ctx->r6;
    after_20:
    // 0x80800E0C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E14: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800E18: andi        $t8, $v0, 0x800
    ctx->r24 = ctx->r2 & 0X800;
    // 0x80800E1C: beql        $t8, $zero, L_80800E38
    if (ctx->r24 == 0) {
        // 0x80800E20: andi        $t9, $v0, 0x2000
        ctx->r25 = ctx->r2 & 0X2000;
            goto L_80800E38;
    }
    goto skip_5;
    // 0x80800E20: andi        $t9, $v0, 0x2000
    ctx->r25 = ctx->r2 & 0X2000;
    skip_5:
    // 0x80800E24: jal         0x8010A624
    // 0x80800E28: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8010A624(rdram, ctx);
        goto after_21;
    // 0x80800E28: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_21:
    // 0x80800E2C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E30: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800E34: andi        $t9, $v0, 0x2000
    ctx->r25 = ctx->r2 & 0X2000;
L_80800E38:
    // 0x80800E38: beql        $t9, $zero, L_80800E54
    if (ctx->r25 == 0) {
        // 0x80800E3C: andi        $t3, $v0, 0x1
        ctx->r11 = ctx->r2 & 0X1;
            goto L_80800E54;
    }
    goto skip_6;
    // 0x80800E3C: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    skip_6:
    // 0x80800E40: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80800E44: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x80800E48: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    // 0x80800E4C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800E50: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
L_80800E54:
    // 0x80800E54: beql        $t3, $zero, L_80800FB0
    if (ctx->r11 == 0) {
        // 0x80800E58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800FB0;
    }
    goto skip_7;
    // 0x80800E58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80800E5C: jal         0x800FFAB0
    // 0x80800E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_22;
    // 0x80800E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800E64: b           L_80800FB0
    // 0x80800E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FB0;
    // 0x80800E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E6C:
    // 0x80800E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E74: jal         0x80800FC0
    // 0x80800E78: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80800FC0_chdoor(rdram, ctx);
        goto after_23;
    // 0x80800E78: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_23:
    // 0x80800E7C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E80: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800E84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800E88: lh          $t4, 0xE($a3)
    ctx->r12 = MEM_H(ctx->r7, 0XE);
    // 0x80800E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E94: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80800E98: nop

    // 0x80800E9C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800EA0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800EA4: jal         0x80103110
    // 0x80800EA8: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    func_80103110(rdram, ctx);
        goto after_24;
    // 0x80800EA8: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    after_24:
    // 0x80800EAC: b           L_80800FB0
    // 0x80800EB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FB0;
    // 0x80800EB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EB4:
    // 0x80800EB4: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x80800EB8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80800EBC: andi        $t6, $t5, 0x1000
    ctx->r14 = ctx->r13 & 0X1000;
    // 0x80800EC0: beql        $t6, $zero, L_80800ED8
    if (ctx->r14 == 0) {
        // 0x80800EC4: lh          $t7, 0xE($a3)
        ctx->r15 = MEM_H(ctx->r7, 0XE);
            goto L_80800ED8;
    }
    goto skip_8;
    // 0x80800EC4: lh          $t7, 0xE($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XE);
    skip_8:
    // 0x80800EC8: jal         0x800FC660
    // 0x80800ECC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800FC660(rdram, ctx);
        goto after_25;
    // 0x80800ECC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_25:
    // 0x80800ED0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800ED4: lh          $t7, 0xE($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XE);
L_80800ED8:
    // 0x80800ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800EE0: bnel        $t7, $zero, L_80800EF8
    if (ctx->r15 != 0) {
        // 0x80800EE4: lw          $v0, 0x0($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X0);
            goto L_80800EF8;
    }
    goto skip_9;
    // 0x80800EE4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    skip_9:
    // 0x80800EE8: jal         0x80800FC0
    // 0x80800EEC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80800FC0_chdoor(rdram, ctx);
        goto after_26;
    // 0x80800EEC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_26:
    // 0x80800EF0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800EF4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
L_80800EF8:
    // 0x80800EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EFC: andi        $t8, $v0, 0x800
    ctx->r24 = ctx->r2 & 0X800;
    // 0x80800F00: beql        $t8, $zero, L_80800F1C
    if (ctx->r24 == 0) {
        // 0x80800F04: andi        $t9, $v0, 0x2000
        ctx->r25 = ctx->r2 & 0X2000;
            goto L_80800F1C;
    }
    goto skip_10;
    // 0x80800F04: andi        $t9, $v0, 0x2000
    ctx->r25 = ctx->r2 & 0X2000;
    skip_10:
    // 0x80800F08: jal         0x8010A63C
    // 0x80800F0C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8010A63C(rdram, ctx);
        goto after_27;
    // 0x80800F0C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_27:
    // 0x80800F10: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F14: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80800F18: andi        $t9, $v0, 0x2000
    ctx->r25 = ctx->r2 & 0X2000;
L_80800F1C:
    // 0x80800F1C: beql        $t9, $zero, L_80800F34
    if (ctx->r25 == 0) {
        // 0x80800F20: lh          $t4, 0xA($a3)
        ctx->r12 = MEM_H(ctx->r7, 0XA);
            goto L_80800F34;
    }
    goto skip_11;
    // 0x80800F20: lh          $t4, 0xA($a3)
    ctx->r12 = MEM_H(ctx->r7, 0XA);
    skip_11:
    // 0x80800F24: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800F28: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80800F2C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x80800F30: lh          $t4, 0xA($a3)
    ctx->r12 = MEM_H(ctx->r7, 0XA);
L_80800F34:
    // 0x80800F34: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800F38: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800F3C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80800F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F48: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800F4C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800F50: jal         0x808005E4
    // 0x80800F54: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    func_808005E4_chdoor(rdram, ctx);
        goto after_28;
    // 0x80800F54: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    after_28:
    // 0x80800F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F5C: jal         0x80103110
    // 0x80800F60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_29;
    // 0x80800F60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x80800F64: b           L_80800FB0
    // 0x80800F68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FB0;
    // 0x80800F68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F6C:
    // 0x80800F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F74: jal         0x80800FC0
    // 0x80800F78: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800FC0_chdoor(rdram, ctx);
        goto after_30;
    // 0x80800F78: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_30:
    // 0x80800F7C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800F80: jal         0x80103110
    // 0x80800F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103110(rdram, ctx);
        goto after_31;
    // 0x80800F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800F88: b           L_80800FB0
    // 0x80800F8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FB0;
    // 0x80800F8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F90:
    // 0x80800F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800F98: jal         0x80800FC0
    // 0x80800F9C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800FC0_chdoor(rdram, ctx);
        goto after_32;
    // 0x80800F9C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_32:
    // 0x80800FA0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800FA4: jal         0x80103110
    // 0x80800FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103110(rdram, ctx);
        goto after_33;
    // 0x80800FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
L_80800FAC:
    // 0x80800FAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800FB0:
    // 0x80800FB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800FB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800FB8: jr          $ra
    // 0x80800FBC: nop

    return;
    // 0x80800FBC: nop

;}
RECOMP_FUNC void func_80800894_chskeletonexplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800894: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80800898: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8080089C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808008A0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x808008A4: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x808008A8: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x808008AC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x808008B0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x808008B4: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x808008B8: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x808008BC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x808008C0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x808008C4: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x808008C8: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x808008CC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808008D0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808008D4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808008D8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808008DC: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x808008E0: or          $fp, $a2, $zero
    ctx->r30 = ctx->r6 | 0;
    // 0x808008E4: jal         0x801039E4
    // 0x808008E8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_801039E4(rdram, ctx);
        goto after_0;
    // 0x808008E8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x808008EC: jal         0x800B27E0
    // 0x808008F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27E0(rdram, ctx);
        goto after_1;
    // 0x808008F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808008F4: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808008F8: jal         0x80087A08
    // 0x808008FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _dbskeleton_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808008FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800900: lhu         $t8, 0x6E($s4)
    ctx->r24 = MEM_HU(ctx->r20, 0X6E);
    // 0x80800904: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x80800908: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080090C: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800910: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80800914: sh          $t0, 0x6E($s4)
    MEM_H(0X6E, ctx->r20) = ctx->r8;
    // 0x80800918: lw          $a2, 0x6C($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X6C);
    // 0x8080091C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800920: andi        $t1, $a2, 0x1FF
    ctx->r9 = ctx->r6 & 0X1FF;
    // 0x80800924: jal         0x80100074
    // 0x80800928: sll         $a2, $t1, 6
    ctx->r6 = S32(ctx->r9 << 6);
    func_80100074(rdram, ctx);
        goto after_3;
    // 0x80800928: sll         $a2, $t1, 6
    ctx->r6 = S32(ctx->r9 << 6);
    after_3:
    // 0x8080092C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800930: jal         0x80100094
    // 0x80800934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800938: lw          $t3, 0x6C($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X6C);
    // 0x8080093C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800940: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800944: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x80800948: beq         $t4, $zero, L_80800A34
    if (ctx->r12 == 0) {
        // 0x8080094C: addiu       $s7, $s4, 0x4
        ctx->r23 = ADD32(ctx->r20, 0X4);
            goto L_80800A34;
    }
    // 0x8080094C: addiu       $s7, $s4, 0x4
    ctx->r23 = ADD32(ctx->r20, 0X4);
    // 0x80800950: lui         $at, 0xC282
    ctx->r1 = S32(0XC282 << 16);
    // 0x80800954: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80800958: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8080095C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800960: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80800964: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800968: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x8080096C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x80800970: addiu       $s3, $sp, 0x84
    ctx->r19 = ADD32(ctx->r29, 0X84);
    // 0x80800974: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80800978:
    // 0x80800978: jal         0x80087A28
    // 0x8080097C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _dbskeleton_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x8080097C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x80800980: addiu       $s1, $s0, 0xC
    ctx->r17 = ADD32(ctx->r16, 0XC);
    // 0x80800984: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800988: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080098C: jal         0x80087A18
    // 0x80800990: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _dbskeleton_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800990: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80800994: jal         0x800EFD24
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFD24(rdram, ctx);
        goto after_7;
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080099C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808009A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808009A4: jal         0x800EE780
    // 0x808009A8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_800EE780(rdram, ctx);
        goto after_8;
    // 0x808009A8: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_8:
    // 0x808009AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808009B0: jal         0x800F1DF4
    // 0x808009B4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_9;
    // 0x808009B4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_9:
    // 0x808009B8: swc1        $f24, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f24.u32l;
    // 0x808009BC: lwc1        $f4, 0x48($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X48);
    // 0x808009C0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808009C4: swc1        $f24, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f24.u32l;
    // 0x808009C8: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x808009CC: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    // 0x808009D0: jal         0x800DC178
    // 0x808009D4: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    func_800DC178(rdram, ctx);
        goto after_10;
    // 0x808009D4: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    after_10:
    // 0x808009D8: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x808009DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808009E0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x808009E4: jal         0x800DC178
    // 0x808009E8: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x808009E8: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    after_11:
    // 0x808009EC: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x808009F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808009F4: add.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x808009F8: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    // 0x808009FC: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x80800A00: add.s       $f8, $f22, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f22.fl + ctx->f6.fl;
    // 0x80800A04: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800A08: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800A0C: jal         0x800EEC30
    // 0x80800A10: nop

    func_800EEC30(rdram, ctx);
        goto after_12;
    // 0x80800A10: nop

    after_12:
    // 0x80800A14: sb          $s6, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = ctx->r22;
    // 0x80800A18: lw          $t5, 0x6C($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X6C);
    // 0x80800A1C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800A20: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x80800A24: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80800A28: sltu        $at, $s2, $t6
    ctx->r1 = ctx->r18 < ctx->r14 ? 1 : 0;
    // 0x80800A2C: bnel        $at, $zero, L_80800978
    if (ctx->r1 != 0) {
        // 0x80800A30: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80800978;
    }
    goto skip_0;
    // 0x80800A30: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
L_80800A34:
    // 0x80800A34: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80800A38: nop

    // 0x80800A3C: swc1        $f24, 0x48($s4)
    MEM_W(0X48, ctx->r20) = ctx->f24.u32l;
    // 0x80800A40: swc1        $f24, 0x44($s4)
    MEM_W(0X44, ctx->r20) = ctx->f24.u32l;
    // 0x80800A44: swc1        $f24, 0x4C($s4)
    MEM_W(0X4C, ctx->r20) = ctx->f24.u32l;
    // 0x80800A48: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80800A4C: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80800A50: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80800A54: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80800A58: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80800A5C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80800A60: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80800A64: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80800A68: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80800A6C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80800A70: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80800A74: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80800A78: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800A7C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800A80: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800A84: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800A88: jr          $ra
    // 0x80800A8C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80800A8C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void basudie_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003AC: jal         0x80091E6C
    // 0x808003B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80091E6C(rdram, ctx);
        goto after_0;
    // 0x808003B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003B4: jal         0x800A4E30
    // 0x808003B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4E30(rdram, ctx);
        goto after_1;
    // 0x808003B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808003BC: jal         0x800A4C68
    // 0x808003C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4C68(rdram, ctx);
        goto after_2;
    // 0x808003C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808003C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003C8: jal         0x800C53EC
    // 0x808003CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C53EC(rdram, ctx);
        goto after_3;
    // 0x808003CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808003D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003D8: jr          $ra
    // 0x808003DC: nop

    return;
    // 0x808003DC: nop

;}
RECOMP_FUNC void sujiggy_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800658: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080065C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800660: jal         0x808000E8
    // 0x80800664: nop

    sujiggy_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800664: nop

    after_0:
    // 0x80800668: jal         0x8080010C
    // 0x8080066C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    sujiggy_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080066C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800670: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800674: bne         $v0, $a0, L_80800684
    if (ctx->r2 != ctx->r4) {
        // 0x80800678: nop
    
            goto L_80800684;
    }
    // 0x80800678: nop

    // 0x8080067C: b           L_808006B4
    // 0x80800680: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006B4;
    // 0x80800680: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800684:
    // 0x80800684: jal         0x80800114
    // 0x80800688: nop

    sujiggy_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800688: nop

    after_2:
    // 0x8080068C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800690: jal         0x800D035C
    // 0x80800694: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D035C(rdram, ctx);
        goto after_3;
    // 0x80800694: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800698: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080069C: subu        $v1, $a1, $v0
    ctx->r3 = SUB32(ctx->r5, ctx->r2);
    // 0x808006A0: blez        $v1, L_808006B0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x808006A4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808006B0;
    }
    // 0x808006A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006A8: b           L_808006B0
    // 0x808006AC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_808006B0;
    // 0x808006AC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_808006B0:
    // 0x808006B0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_808006B4:
    // 0x808006B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808006BC: jr          $ra
    // 0x808006C0: nop

    return;
    // 0x808006C0: nop

;}
RECOMP_FUNC void func_800D87EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D87EC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D87F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D87F4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D87F8: jr          $ra
    // 0x800D87FC: lw          $v0, -0x4090($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4090);
    return;
    // 0x800D87FC: lw          $v0, -0x4090($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4090);
;}
RECOMP_FUNC void _sulights_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A8A8: syscall     854
    recomp_syscall_handler(rdram, ctx, 0x8008A8A8);
    return;
    // 0x8008A8AC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void basnowball_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B34: jal         0x800F796C
    // 0x80800B38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800F796C(rdram, ctx);
        goto after_0;
    // 0x80800B38: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80800B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B44: jr          $ra
    // 0x80800B48: nop

    return;
    // 0x80800B48: nop

;}
RECOMP_FUNC void _sucoaster_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A168: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A168);
    return;
    // 0x8008A16C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_80802330_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802330: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1364, 0X25A4) << 16);
    // 0x80802334: lwc1        $f4, 0x25A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1364, 0X25A4));
    // 0x80802338: jr          $ra
    // 0x8080233C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8080233C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_800FB5BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB5BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FB5C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FB5C4: lbu         $t6, 0x33($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X33);
    // 0x800FB5C8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800FB5CC: beql        $t6, $zero, L_800FB5EC
    if (ctx->r14 == 0) {
        // 0x800FB5D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800FB5EC;
    }
    goto skip_0;
    // 0x800FB5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800FB5D4: lh          $a0, 0x28($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X28);
    // 0x800FB5D8: jal         0x800FED90
    // 0x800FB5DC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800FED90(rdram, ctx);
        goto after_0;
    // 0x800FB5DC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800FB5E0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800FB5E4: sb          $zero, 0x33($a1)
    MEM_B(0X33, ctx->r5) = 0;
    // 0x800FB5E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800FB5EC:
    // 0x800FB5EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FB5F0: jr          $ra
    // 0x800FB5F4: nop

    return;
    // 0x800FB5F4: nop

;}
RECOMP_FUNC void func_80105C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105C20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105C28: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80105C2C: jal         0x800B3268
    // 0x80105C30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    freelist_new(rdram, ctx);
        goto after_0;
    // 0x80105C30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80105C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105C38: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80105C3C: sw          $v0, 0x6ED0($at)
    MEM_W(0X6ED0, ctx->r1) = ctx->r2;
    // 0x80105C40: jr          $ra
    // 0x80105C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
