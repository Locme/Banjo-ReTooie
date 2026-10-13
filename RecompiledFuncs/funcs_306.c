#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bainput_func_80097B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097B28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097B30: jal         0x80091970
    // 0x80097B34: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bakey_heldCount(rdram, ctx);
        goto after_0;
    // 0x80097B34: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80097B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097B3C: slti        $t6, $v0, 0x7
    ctx->r14 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80097B40: xori        $v0, $t6, 0x1
    ctx->r2 = ctx->r14 ^ 0X1;
    // 0x80097B44: jr          $ra
    // 0x80097B48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80097B48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800D5E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D5E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5E30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D5E34: jal         0x800D5440
    // 0x800D5E38: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_800D5440(rdram, ctx);
        goto after_0;
    // 0x800D5E38: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x800D5E3C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800D5E40: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800D5E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D5E48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D5E4C: jr          $ra
    // 0x800D5E50: nop

    return;
    // 0x800D5E50: nop

;}
RECOMP_FUNC void func_8009316C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009316C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80093170: beq         $a1, $zero, L_8009319C
    if (ctx->r5 == 0) {
        // 0x80093174: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009319C;
    }
    // 0x80093174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093178: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x8009317C: lh          $t6, 0x9E($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X9E);
    // 0x80093180: beql        $a1, $t6, L_800931A0
    if (ctx->r5 == ctx->r14) {
        // 0x80093184: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800931A0;
    }
    goto skip_0;
    // 0x80093184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80093188: sh          $a1, 0x9E($v0)
    MEM_H(0X9E, ctx->r2) = ctx->r5;
    // 0x8009318C: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x80093190: lh          $a2, 0x9C($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X9C);
    // 0x80093194: jal         0x80093070
    // 0x80093198: addiu       $a3, $v0, 0xA0
    ctx->r7 = ADD32(ctx->r2, 0XA0);
    func_80093070(rdram, ctx);
        goto after_0;
    // 0x80093198: addiu       $a3, $v0, 0xA0
    ctx->r7 = ADD32(ctx->r2, 0XA0);
    after_0:
L_8009319C:
    // 0x8009319C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800931A0:
    // 0x800931A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800931A4: jr          $ra
    // 0x800931A8: nop

    return;
    // 0x800931A8: nop

;}
RECOMP_FUNC void func_80800094_fxripple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800098: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080009C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000A0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x808000A4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x808000A8: jal         0x800EE7F8
    // 0x808000AC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808000AC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x808000B0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808000B4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808000B8: jal         0x80800000
    // 0x808000BC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80800000_fxripple(rdram, ctx);
        goto after_1;
    // 0x808000BC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x808000C0: bne         $v0, $zero, L_808000D0
    if (ctx->r2 != 0) {
        // 0x808000C4: lwc1        $f4, 0x34($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
            goto L_808000D0;
    }
    // 0x808000C4: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808000C8: b           L_8080017C
    // 0x808000CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080017C;
    // 0x808000CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000D0:
    // 0x808000D0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808000D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000D8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808000DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808000E0: jal         0x800B5BE4
    // 0x808000E4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    func_800B5BE4(rdram, ctx);
        goto after_2;
    // 0x808000E4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x808000E8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808000EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: beq         $a1, $zero, L_80800124
    if (ctx->r5 == 0) {
        // 0x808000F8: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80800124;
    }
    // 0x808000F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000FC: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800100: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800104: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800108: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8080010C: nop

    // 0x80800110: sll         $t7, $a2, 16
    ctx->r15 = S32(ctx->r6 << 16);
    // 0x80800114: jal         0x800BA660
    // 0x80800118: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    func_800BA660(rdram, ctx);
        goto after_3;
    // 0x80800118: sra         $a2, $t7, 16
    ctx->r6 = S32(SIGNED(ctx->r15) >> 16);
    after_3:
    // 0x8080011C: b           L_8080012C
    // 0x80800120: nop

        goto L_8080012C;
    // 0x80800120: nop

L_80800124:
    // 0x80800124: jal         0x800BA660
    // 0x80800128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BA660(rdram, ctx);
        goto after_4;
    // 0x80800128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_8080012C:
    // 0x8080012C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2818, 0X334) << 16);
    // 0x80800130: addiu       $t9, $t9, 0x334
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2818, 0X334));
    // 0x80800134: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800140: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800144: jal         0x800BABB8
    // 0x80800148: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_5;
    // 0x80800148: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_5:
    // 0x8080014C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80800150: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2818, 0X320) << 16);
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800158: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8080015C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80800160: lw          $t2, 0x320($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(2818, 0X320));
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800168: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080016C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800170: jal         0x800BABB8
    // 0x80800174: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x80800174: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_6:
    // 0x80800178: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8080017C:
    // 0x8080017C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800180: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800184: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800188: jr          $ra
    // 0x8080018C: nop

    return;
    // 0x8080018C: nop

;}
RECOMP_FUNC void func_8080200C_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080200C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802010: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80802014: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80802018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080201C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80802020: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802024: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80802028: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(832, 0X2FC4) << 16);
    // 0x8080202C: addiu       $t7, $t7, 0x2FC4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(832, 0X2FC4));
    // 0x80802030: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80802034: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80802038: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080203C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80802040: jal         0x800BABB8
    // 0x80802044: nop

    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x80802044: nop

    after_0:
    // 0x80802048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080204C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802050: jr          $ra
    // 0x80802054: nop

    return;
    // 0x80802054: nop

;}
RECOMP_FUNC void func_80800A28_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A28: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A30: jal         0x80104248
    // 0x80800A34: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80800A34: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A38: jal         0x8008AEDC
    // 0x80800A3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008AEDC(rdram, ctx);
        goto after_1;
    // 0x80800A3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800A40: jal         0x8008C27C
    // 0x80800A44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008C27C(rdram, ctx);
        goto after_2;
    // 0x80800A44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800A48: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800A4C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800A50: jal         0x80100094
    // 0x80800A54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800A54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800A58: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800A5C: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x80800A60: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80800A64: jal         0x800DFC20
    // 0x80800A68: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800DFC20(rdram, ctx);
        goto after_4;
    // 0x80800A68: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_4:
    // 0x80800A6C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A70: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800A74: lwc1        $f6, 0x28($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80800A78: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800A7C: swc1        $f8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f8.u32l;
    // 0x80800A80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800A88: jr          $ra
    // 0x80800A8C: nop

    return;
    // 0x80800A8C: nop

;}
RECOMP_FUNC void func_808003B8_baswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808003BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003C0: jal         0x8009BB24
    // 0x808003C4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_0;
    // 0x808003C4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x808003C8: jal         0x800EEF94
    // 0x808003CC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EEF94(rdram, ctx);
        goto after_1;
    // 0x808003CC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x808003D0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808003D4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808003E4: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x808003E8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808003EC: jal         0x800F10B4
    // 0x808003F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x808003F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x808003F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003FC: jr          $ra
    // 0x80800400: nop

    return;
    // 0x80800400: nop

;}
RECOMP_FUNC void func_8009E83C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E83C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E844: lw          $t6, 0x120($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X120);
    // 0x8009E848: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x8009E84C: jal         0x8009CB90
    // 0x8009E850: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009CB90(rdram, ctx);
        goto after_0;
    // 0x8009E850: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009E854: beq         $v0, $zero, L_8009E864
    if (ctx->r2 == 0) {
        // 0x8009E858: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8009E864;
    }
    // 0x8009E858: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009E85C: jalr        $v0
    // 0x8009E860: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8009E860: nop

    after_1:
L_8009E864:
    // 0x8009E864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E86C: jr          $ra
    // 0x8009E870: nop

    return;
    // 0x8009E870: nop

    // 0x8009E874: nop

    // 0x8009E878: nop

    // 0x8009E87C: nop

;}
RECOMP_FUNC void func_800F0410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0410: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800F0414: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F0418: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800F041C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F0420: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800F0424: addiu       $a2, $a1, 0xC
    ctx->r6 = ADD32(ctx->r5, 0XC);
    // 0x800F0428: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x800F042C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x800F0430: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800F0434: jal         0x800F0274
    // 0x800F0438: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    func_800F0274(rdram, ctx);
        goto after_0;
    // 0x800F0438: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800F043C: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x800F0440: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800F0444: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800F0448: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x800F044C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800F0450: jal         0x800F0274
    // 0x800F0454: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_800F0274(rdram, ctx);
        goto after_1;
    // 0x800F0454: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x800F0458: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800F045C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800F0460: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x800F0464: jal         0x800F0274
    // 0x800F0468: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    func_800F0274(rdram, ctx);
        goto after_2;
    // 0x800F0468: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x800F046C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x800F0470: jal         0x800EEB40
    // 0x800F0474: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x800F0474: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800F0478: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800F047C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800F0480: jal         0x800EEB40
    // 0x800F0484: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EEB40(rdram, ctx);
        goto after_4;
    // 0x800F0484: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800F0488: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800F048C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F0490: jal         0x800EEB40
    // 0x800F0494: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    func_800EEB40(rdram, ctx);
        goto after_5;
    // 0x800F0494: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x800F0498: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800F049C: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800F04A0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800F04A4: nop

    // 0x800F04A8: bc1fl       L_800F04E8
    if (!c1cs) {
        // 0x800F04AC: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_800F04E8;
    }
    goto skip_0;
    // 0x800F04AC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x800F04B0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800F04B4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800F04B8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F04BC: bc1f        L_800F04D4
    if (!c1cs) {
        // 0x800F04C0: nop
    
            goto L_800F04D4;
    }
    // 0x800F04C0: nop

    // 0x800F04C4: jal         0x800EE7F8
    // 0x800F04C8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x800F04C8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_6:
    // 0x800F04CC: b           L_800F0514
    // 0x800F04D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800F0514;
    // 0x800F04D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F04D4:
    // 0x800F04D4: jal         0x800EE7F8
    // 0x800F04D8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x800F04D8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_7:
    // 0x800F04DC: b           L_800F0514
    // 0x800F04E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800F0514;
    // 0x800F04E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F04E4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800F04E8:
    // 0x800F04E8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800F04EC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800F04F0: bc1f        L_800F0508
    if (!c1cs) {
        // 0x800F04F4: nop
    
            goto L_800F0508;
    }
    // 0x800F04F4: nop

    // 0x800F04F8: jal         0x800EE7F8
    // 0x800F04FC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x800F04FC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_8:
    // 0x800F0500: b           L_800F0514
    // 0x800F0504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800F0514;
    // 0x800F0504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F0508:
    // 0x800F0508: jal         0x800EE7F8
    // 0x800F050C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x800F050C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_9:
    // 0x800F0510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F0514:
    // 0x800F0514: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F0518: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800F051C: jr          $ra
    // 0x800F0520: nop

    return;
    // 0x800F0520: nop

;}
RECOMP_FUNC void func_8080000C_chklungospiral(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800018: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8080001C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800020: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80800024: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    // 0x80800028: jal         0x8008A0C8
    // 0x8080002C: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080002C: addiu       $a2, $zero, 0x33
    ctx->r6 = ADD32(0, 0X33);
    after_0:
    // 0x80800030: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800034: jal         0x8008A4A0
    // 0x80800038: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    _subaddieDll_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800038: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x8080003C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800040: jal         0x80105A9C
    // 0x80800044: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    func_80105A9C(rdram, ctx);
        goto after_2;
    // 0x80800044: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_2:
    // 0x80800048: jal         0x80105BAC
    // 0x8080004C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80105BAC(rdram, ctx);
        goto after_3;
    // 0x8080004C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x80800050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800054: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800058: jr          $ra
    // 0x8080005C: nop

    return;
    // 0x8080005C: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A98: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A98);
    return;
    // 0x80082A9C: addi        $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
;}
RECOMP_FUNC void func_80802C9C_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802CA4: jal         0x80101F24
    // 0x80802CA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80101F24(rdram, ctx);
        goto after_0;
    // 0x80802CA8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80802CAC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80802CB0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80802CB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802CB8: beq         $a1, $zero, L_80802CE0
    if (ctx->r5 == 0) {
        // 0x80802CBC: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_80802CE0;
    }
    // 0x80802CBC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80802CC0: beq         $a1, $at, L_80802CF4
    if (ctx->r5 == ctx->r1) {
        // 0x80802CC4: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_80802CF4;
    }
    // 0x80802CC4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80802CC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802CCC: beq         $a1, $at, L_80802D08
    if (ctx->r5 == ctx->r1) {
        // 0x80802CD0: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_80802D08;
    }
    // 0x80802CD0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80802CD4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80802CD8: b           L_80802D1C
    // 0x80802CDC: nop

        goto L_80802D1C;
    // 0x80802CDC: nop

L_80802CE0:
    // 0x80802CE0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1360, 0X4A4C) << 16);
    // 0x80802CE4: jal         0x800F3780
    // 0x80802CE8: addiu       $a1, $a1, 0x4A4C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4A4C));
    func_800F3780(rdram, ctx);
        goto after_1;
    // 0x80802CE8: addiu       $a1, $a1, 0x4A4C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4A4C));
    after_1:
    // 0x80802CEC: b           L_80802D20
    // 0x80802CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802D20;
    // 0x80802CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802CF4:
    // 0x80802CF4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1360, 0X4A64) << 16);
    // 0x80802CF8: jal         0x800F3780
    // 0x80802CFC: addiu       $a1, $a1, 0x4A64
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4A64));
    func_800F3780(rdram, ctx);
        goto after_2;
    // 0x80802CFC: addiu       $a1, $a1, 0x4A64
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4A64));
    after_2:
    // 0x80802D00: b           L_80802D20
    // 0x80802D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802D20;
    // 0x80802D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802D08:
    // 0x80802D08: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1360, 0X4A7C) << 16);
    // 0x80802D0C: jal         0x800F3780
    // 0x80802D10: addiu       $a1, $a1, 0x4A7C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4A7C));
    func_800F3780(rdram, ctx);
        goto after_3;
    // 0x80802D10: addiu       $a1, $a1, 0x4A7C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4A7C));
    after_3:
    // 0x80802D14: b           L_80802D20
    // 0x80802D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802D20;
    // 0x80802D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802D1C:
    // 0x80802D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802D20:
    // 0x80802D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802D24: jr          $ra
    // 0x80802D28: nop

    return;
    // 0x80802D28: nop

;}
RECOMP_FUNC void func_8080003C_chfactorygoblin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800040: addiu       $at, $zero, 0xB6
    ctx->r1 = ADD32(0, 0XB6);
    // 0x80800044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080004C: bne         $a1, $at, L_80800060
    if (ctx->r5 != ctx->r1) {
        // 0x80800050: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800060;
    }
    // 0x80800050: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800054: jal         0x8080007C
    // 0x80800058: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8080007C_chfactorygoblin(rdram, ctx);
        goto after_0;
    // 0x80800058: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080005C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_80800060:
    // 0x80800060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800064: jal         0x8008A1A0
    // 0x80800068: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _sucoaster_entrypoint_21(rdram, ctx);
        goto after_1;
    // 0x80800068: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080006C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800074: jr          $ra
    // 0x80800078: nop

    return;
    // 0x80800078: nop

;}
RECOMP_FUNC void func_80014F58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014F58: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014F5C: jr          $ra
    // 0x80014F60: lh          $v0, -0x70A0($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X70A0);
    return;
    // 0x80014F60: lh          $v0, -0x70A0($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X70A0);
;}
RECOMP_FUNC void func_808000B0_chdiggerbossdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808000B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C0: jal         0x800F54E4
    // 0x808000C4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808000C4: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    after_0:
    // 0x808000C8: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808000CC: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808000D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000D4: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x808000D8: beq         $t6, $at, L_808000F8
    if (ctx->r14 == ctx->r1) {
        // 0x808000DC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808000F8;
    }
    // 0x808000DC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000E0: beq         $t6, $at, L_808001F8
    if (ctx->r14 == ctx->r1) {
        // 0x808000E4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808001F8;
    }
    // 0x808000E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000E8: beq         $t6, $at, L_8080019C
    if (ctx->r14 == ctx->r1) {
        // 0x808000EC: addiu       $t7, $s0, 0x4
        ctx->r15 = ADD32(ctx->r16, 0X4);
            goto L_8080019C;
    }
    // 0x808000EC: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x808000F0: b           L_80800274
    // 0x808000F4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_80800274;
    // 0x808000F4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_808000F8:
    // 0x808000F8: jal         0x800D9078
    // 0x808000FC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x808000FC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x80800100: beq         $v0, $zero, L_80800140
    if (ctx->r2 == 0) {
        // 0x80800104: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80800140;
    }
    // 0x80800104: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800108: jal         0x800DA298
    // 0x8080010C: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080010C: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_2:
    // 0x80800110: beql        $v0, $zero, L_80800130
    if (ctx->r2 == 0) {
        // 0x80800114: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800130;
    }
    goto skip_0;
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800118: jal         0x80085750
    // 0x8080011C: nop

    _capod_entrypoint_22(rdram, ctx);
        goto after_3;
    // 0x8080011C: nop

    after_3:
    // 0x80800120: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800124: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800128: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800130:
    // 0x80800130: jal         0x80101FDC
    // 0x80800134: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x80800134: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800138: b           L_80800148
    // 0x8080013C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_80800148;
    // 0x8080013C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800140:
    // 0x80800140: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80800144: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800148:
    // 0x80800148: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x8080014C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800150: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800154: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800158: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    // 0x8080015C: jal         0x800F12D4
    // 0x80800160: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_5;
    // 0x80800160: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80800164: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800168: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080016C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800170: jal         0x800EE7F8
    // 0x80800174: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800174: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x80800178: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080017C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800180: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800184: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800188: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8080018C: jal         0x800F8294
    // 0x80800190: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    func_800F8294(rdram, ctx);
        goto after_7;
    // 0x80800190: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x80800194: b           L_80800274
    // 0x80800198: nop

        goto L_80800274;
    // 0x80800198: nop

L_8080019C:
    // 0x8080019C: jal         0x800D9078
    // 0x808001A0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_8;
    // 0x808001A0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_8:
    // 0x808001A4: beq         $v0, $zero, L_808001CC
    if (ctx->r2 == 0) {
        // 0x808001A8: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_808001CC;
    }
    // 0x808001A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808001AC: addiu       $a0, $zero, 0x15D
    ctx->r4 = ADD32(0, 0X15D);
    // 0x808001B0: jal         0x80087A58
    // 0x808001B4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x808001B4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: jal         0x80101FDC
    // 0x808001C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x808001C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808001C4: b           L_808001D4
    // 0x808001C8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
        goto L_808001D4;
    // 0x808001C8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_808001CC:
    // 0x808001CC: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x808001D0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_808001D4:
    // 0x808001D4: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808001D8: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    // 0x808001DC: lui         $a3, 0xC3FA
    ctx->r7 = S32(0XC3FA << 16);
    // 0x808001E0: jal         0x800F12D4
    // 0x808001E4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_11;
    // 0x808001E4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_11:
    // 0x808001E8: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x808001EC: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
    // 0x808001F0: b           L_80800274
    // 0x808001F4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
        goto L_80800274;
    // 0x808001F4: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_808001F8:
    // 0x808001F8: jal         0x800F55FC
    // 0x808001FC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800F55FC(rdram, ctx);
        goto after_12;
    // 0x808001FC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_12:
    // 0x80800200: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x80800204: bgez        $t3, L_8080026C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800208: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080026C;
    }
    // 0x80800208: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080020C: jal         0x80016B30
    // 0x80800210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_13;
    // 0x80800210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80800214: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800218: bne         $v0, $at, L_8080026C
    if (ctx->r2 != ctx->r1) {
        // 0x8080021C: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_8080026C;
    }
    // 0x8080021C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800220: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800224: jal         0x800F4BB8
    // 0x80800228: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F4BB8(rdram, ctx);
        goto after_14;
    // 0x80800228: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x8080022C: beq         $v0, $zero, L_8080026C
    if (ctx->r2 == 0) {
        // 0x80800230: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8080026C;
    }
    // 0x80800230: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800234: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800238: addiu       $a2, $zero, 0x54
    ctx->r6 = ADD32(0, 0X54);
    // 0x8080023C: jal         0x80085748
    // 0x80800240: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_21(rdram, ctx);
        goto after_15;
    // 0x80800240: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_15:
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: jal         0x80101FDC
    // 0x8080024C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_16;
    // 0x8080024C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_16:
    // 0x80800250: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800254: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800258: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080025C: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x80800260: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80800264: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
    // 0x80800268: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_8080026C:
    // 0x8080026C: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x80800270: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_80800274:
    // 0x80800274: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1484, 0X478) << 16);
    // 0x80800278: addiu       $a3, $a3, 0x478
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1484, 0X478));
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800280: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800284: jal         0x80089D50
    // 0x80800288: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_17;
    // 0x80800288: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    after_17:
    // 0x8080028C: jal         0x80800370
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800370_chdiggerbossdoor(rdram, ctx);
        goto after_18;
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800294: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800298: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080029C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808002A0: jr          $ra
    // 0x808002A4: nop

    return;
    // 0x808002A4: nop

;}
RECOMP_FUNC void func_8009DDDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009DDDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009DDE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009DDE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8009DDE8: jal         0x8009C128
    // 0x8009DDEC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8009DDEC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8009DDF0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8009DDF4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8009DDF8: lw          $t7, 0x104($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X104);
    // 0x8009DDFC: jal         0x800C35E8
    // 0x8009DE00: lbu         $a0, 0x3($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X3);
    func_800C35E8(rdram, ctx);
        goto after_1;
    // 0x8009DE00: lbu         $a0, 0x3($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X3);
    after_1:
    // 0x8009DE04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009DE08: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009DE0C: jr          $ra
    // 0x8009DE10: nop

    return;
    // 0x8009DE10: nop

;}
RECOMP_FUNC void func_800FE844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE844: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE848: jr          $ra
    // 0x800FE84C: sb          $a0, 0x59CE($at)
    MEM_B(0X59CE, ctx->r1) = ctx->r4;
    return;
    // 0x800FE84C: sb          $a0, 0x59CE($at)
    MEM_B(0X59CE, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void vector_index_of(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B28E8: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800B28EC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800B28F0: subu        $t7, $a1, $t6
    ctx->r15 = SUB32(ctx->r5, ctx->r14);
    // 0x800B28F4: div         $zero, $t7, $t8
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r24)));
    // 0x800B28F8: mflo        $v0
    ctx->r2 = lo;
    // 0x800B28FC: bne         $t8, $zero, L_800B2908
    if (ctx->r24 != 0) {
        // 0x800B2900: nop
    
            goto L_800B2908;
    }
    // 0x800B2900: nop

    // 0x800B2904: break       7
    do_break(2148215044);
L_800B2908:
    // 0x800B2908: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B290C: bne         $t8, $at, L_800B2920
    if (ctx->r24 != ctx->r1) {
        // 0x800B2910: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B2920;
    }
    // 0x800B2910: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2914: bne         $t7, $at, L_800B2920
    if (ctx->r15 != ctx->r1) {
        // 0x800B2918: nop
    
            goto L_800B2920;
    }
    // 0x800B2918: nop

    // 0x800B291C: break       6
    do_break(2148215068);
L_800B2920:
    // 0x800B2920: jr          $ra
    // 0x800B2924: nop

    return;
    // 0x800B2924: nop

;}
RECOMP_FUNC void func_800C3224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3224: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3228: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800C322C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3230: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C3234: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800C3238: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C323C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C3240: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x800C3244: jal         0x800C395C
    // 0x800C3248: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    func_800C395C(rdram, ctx);
        goto after_0;
    // 0x800C3248: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800C324C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3250: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C3254: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800C3258: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800C325C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800C3260: bc1fl       L_800C3274
    if (!c1cs) {
        // 0x800C3264: c.lt.s      $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
            goto L_800C3274;
    }
    goto skip_0;
    // 0x800C3264: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    skip_0:
    // 0x800C3268: b           L_800C32A4
    // 0x800C326C: add.s       $f20, $f0, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f14.fl;
        goto L_800C32A4;
    // 0x800C326C: add.s       $f20, $f0, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x800C3270: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
L_800C3274:
    // 0x800C3274: nop

    // 0x800C3278: bc1f        L_800C3288
    if (!c1cs) {
        // 0x800C327C: nop
    
            goto L_800C3288;
    }
    // 0x800C327C: nop

    // 0x800C3280: b           L_800C32A4
    // 0x800C3284: sub.s       $f20, $f0, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f14.fl;
        goto L_800C32A4;
    // 0x800C3284: sub.s       $f20, $f0, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f14.fl;
L_800C3288:
    // 0x800C3288: jal         0x800DC264
    // 0x800C328C: neg.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = -ctx->f14.fl;
    func_800DC264(rdram, ctx);
        goto after_1;
    // 0x800C328C: neg.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = -ctx->f14.fl;
    after_1:
    // 0x800C3290: add.s       $f12, $f20, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x800C3294: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C3298: jal         0x800F0D50
    // 0x800C329C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800F0D50(rdram, ctx);
        goto after_2;
    // 0x800C329C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800C32A0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_800C32A4:
    // 0x800C32A4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800C32A8: jal         0x800C31DC
    // 0x800C32AC: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    func_800C31DC(rdram, ctx);
        goto after_3;
    // 0x800C32AC: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    after_3:
    // 0x800C32B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C32B4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800C32B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C32BC: jr          $ra
    // 0x800C32C0: nop

    return;
    // 0x800C32C0: nop

;}
RECOMP_FUNC void func_808000BC_chfantasyonion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808000C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000CC: jal         0x8010568C
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010568C(rdram, ctx);
        goto after_0;
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000D4: beq         $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x808000D8: nop
    
            goto L_80800224;
    }
    // 0x808000D8: nop

    // 0x808000DC: jal         0x80105634
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105634(rdram, ctx);
        goto after_1;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000E4: lui         $at, 0x42C6
    ctx->r1 = S32(0X42C6 << 16);
    // 0x808000E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000EC: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808000F0: lbu         $t6, 0x77($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X77);
    // 0x808000F4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808000F8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808000FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800100: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80800104: sb          $t7, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r15;
    // 0x80800108: bc1fl       L_80800124
    if (!c1cs) {
        // 0x8080010C: lbu         $t1, 0x65($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X65);
            goto L_80800124;
    }
    goto skip_0;
    // 0x8080010C: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x80800110: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800114: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80800118: b           L_8080012C
    // 0x8080011C: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
        goto L_8080012C;
    // 0x8080011C: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80800120: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
L_80800124:
    // 0x80800124: andi        $t2, $t1, 0xFFEF
    ctx->r10 = ctx->r9 & 0XFFEF;
    // 0x80800128: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_8080012C:
    // 0x8080012C: jal         0x800F13C4
    // 0x80800130: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    func_800F13C4(rdram, ctx);
        goto after_2;
    // 0x80800130: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    after_2:
    // 0x80800134: lhu         $t3, 0x76($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X76);
    // 0x80800138: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8080013C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800140: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x80800144: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x80800148: mflo        $t5
    ctx->r13 = lo;
    // 0x8080014C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80800150: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800154: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800158: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080015C: lui         $a2, 0x42C6
    ctx->r6 = S32(0X42C6 << 16);
    // 0x80800160: jal         0x800F10B4
    // 0x80800164: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800164: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x80800168: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x8080016C: jal         0x80088498
    // 0x80800170: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _glsplinefind_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800170: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80800174: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80800178: nop

    // 0x8080017C: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800180: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800184: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80800188: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8080018C: jal         0x800D7520
    // 0x80800190: nop

    func_800D7520(rdram, ctx);
        goto after_5;
    // 0x80800190: nop

    after_5:
    // 0x80800194: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800198: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8080019C: jal         0x800C7A68
    // 0x808001A0: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800C7A68(rdram, ctx);
        goto after_6;
    // 0x808001A0: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_6:
    // 0x808001A4: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808001A8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808001AC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x808001B0: jal         0x800D7520
    // 0x808001B4: nop

    func_800D7520(rdram, ctx);
        goto after_7;
    // 0x808001B4: nop

    after_7:
    // 0x808001B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001BC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808001C0: jal         0x800C7A68
    // 0x808001C4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_800C7A68(rdram, ctx);
        goto after_8;
    // 0x808001C4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_8:
    // 0x808001C8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808001CC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808001D0: jal         0x800EEDE8
    // 0x808001D4: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800EEDE8(rdram, ctx);
        goto after_9;
    // 0x808001D4: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_9:
    // 0x808001D8: beql        $v0, $zero, L_80800210
    if (ctx->r2 == 0) {
        // 0x808001DC: lbu         $t2, 0x65($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X65);
            goto L_80800210;
    }
    goto skip_1;
    // 0x808001DC: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    skip_1:
    // 0x808001E0: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808001E4: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x808001E8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808001EC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808001F0: ori         $t0, $t9, 0x8
    ctx->r8 = ctx->r25 | 0X8;
    // 0x808001F4: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x808001F8: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x808001FC: jal         0x800D8648
    // 0x80800200: nop

    func_800D8648(rdram, ctx);
        goto after_10;
    // 0x80800200: nop

    after_10:
    // 0x80800204: b           L_8080021C
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080021C;
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
L_80800210:
    // 0x80800210: andi        $t3, $t2, 0xFFF7
    ctx->r11 = ctx->r10 & 0XFFF7;
    // 0x80800214: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080021C:
    // 0x8080021C: jal         0x80101FDC
    // 0x80800220: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x80800220: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
L_80800224:
    // 0x80800224: jal         0x80800000
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_chfantasyonion(rdram, ctx);
        goto after_12;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080022C: jal         0x800DC0C0
    // 0x80800230: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_13;
    // 0x80800230: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    after_13:
    // 0x80800234: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800238: jal         0x80101EE4
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101EE4(rdram, ctx);
        goto after_14;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800240: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800244: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800248: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8080024C: jr          $ra
    // 0x80800250: nop

    return;
    // 0x80800250: nop

;}
RECOMP_FUNC void func_80111144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111144: jr          $ra
    // 0x80111148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80111148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void capod_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800358: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080035C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800360: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800364: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800368: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080036C: jal         0x8008FFE8
    // 0x80800370: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x80800370: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800374: beq         $v0, $zero, L_808003A4
    if (ctx->r2 == 0) {
        // 0x80800378: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808003A4;
    }
    // 0x80800378: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080037C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800380: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800384: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800388: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8080038C: jal         0x80089590
    // 0x80800390: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    _ncpod_entrypoint_26(rdram, ctx);
        goto after_1;
    // 0x80800390: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x80800394: beql        $v0, $zero, L_808003A8
    if (ctx->r2 == 0) {
        // 0x80800398: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808003A8;
    }
    goto skip_0;
    // 0x80800398: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8080039C: b           L_808003A8
    // 0x808003A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808003A8;
    // 0x808003A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003A4:
    // 0x808003A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003A8:
    // 0x808003A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003B0: jr          $ra
    // 0x808003B4: nop

    return;
    // 0x808003B4: nop

;}
RECOMP_FUNC void func_800AA0C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA0C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AA0C8: jr          $ra
    // 0x800AA0CC: lh          $v0, 0x7780($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7780);
    return;
    // 0x800AA0CC: lh          $v0, 0x7780($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7780);
;}
RECOMP_FUNC void func_80800024_chlavahand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800030: lbu         $t6, 0x7A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7A);
    // 0x80800034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800038: andi        $t7, $t6, 0xFF3F
    ctx->r15 = ctx->r14 & 0XFF3F;
    // 0x8080003C: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x80800040: jal         0x800F54E4
    // 0x80800044: sb          $t8, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r24;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800044: sb          $t8, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r24;
    after_0:
    // 0x80800048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080004C: jal         0x800F5A00
    // 0x80800050: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x80800050: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80800054: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800058: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8080005C: jal         0x800F1F0C
    // 0x80800060: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    func_800F1F0C(rdram, ctx);
        goto after_2;
    // 0x80800060: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    after_2:
    // 0x80800064: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80800068: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080006C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800070: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80800074: nop

    // 0x80800078: bc1fl       L_808000C0
    if (!c1cs) {
        // 0x8080007C: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_808000C0;
    }
    goto skip_0;
    // 0x8080007C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80800080: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8080008C: nop

    // 0x80800090: bc1fl       L_808000C0
    if (!c1cs) {
        // 0x80800094: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_808000C0;
    }
    goto skip_1;
    // 0x80800094: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x80800098: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8080009C: addiu       $a1, $zero, 0x925
    ctx->r5 = ADD32(0, 0X925);
    // 0x808000A0: jal         0x80103140
    // 0x808000A4: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    func_80103140(rdram, ctx);
        goto after_3;
    // 0x808000A4: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    after_3:
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: jal         0x80102424
    // 0x808000B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x808000B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808000B4: b           L_80800108
    // 0x808000B8: nop

        goto L_80800108;
    // 0x808000B8: nop

    // 0x808000BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_808000C0:
    // 0x808000C0: nop

    // 0x808000C4: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x808000C8: nop

    // 0x808000CC: bc1f        L_80800108
    if (!c1cs) {
        // 0x808000D0: nop
    
            goto L_80800108;
    }
    // 0x808000D0: nop

    // 0x808000D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x808000E0: nop

    // 0x808000E4: bc1f        L_80800108
    if (!c1cs) {
        // 0x808000E8: nop
    
            goto L_80800108;
    }
    // 0x808000E8: nop

    // 0x808000EC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x808000F0: addiu       $a1, $zero, 0x92C
    ctx->r5 = ADD32(0, 0X92C);
    // 0x808000F4: jal         0x80103140
    // 0x808000F8: lhu         $a2, 0x16($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X16);
    func_80103140(rdram, ctx);
        goto after_5;
    // 0x808000F8: lhu         $a2, 0x16($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X16);
    after_5:
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: jal         0x80102424
    // 0x80800104: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800104: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
L_80800108:
    // 0x80800108: jal         0x8010A590
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_7;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800114: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800118: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void _bskaztorpedo_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083780: syscall     72
    recomp_syscall_handler(rdram, ctx, 0x80083780);
    return;
    // 0x80083784: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void chalienkids_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1324, 0X21B4) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0x21B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1324, 0X21B4));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0x21B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1324, 0X21B4));
;}
RECOMP_FUNC void _baswim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085268: syscall     156
    recomp_syscall_handler(rdram, ctx, 0x80085268);
    return;
    // 0x8008526C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void _suquiz_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A818: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A818);
    return;
    // 0x8008A81C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _fxairbub_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800889C8: syscall     716
    recomp_syscall_handler(rdram, ctx, 0x800889C8);
    return;
    // 0x800889CC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void sufreezy_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D4: jal         0x80106790
    // 0x808001D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808001D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808001DC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808001E0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001E4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808001E8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001EC: jal         0x800DC178
    // 0x808001F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x808001F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808001F4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808001F8: swc1        $f0, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f0.u32l;
    // 0x808001FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800200: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800204: jr          $ra
    // 0x80800208: nop

    return;
    // 0x80800208: nop

;}
RECOMP_FUNC void _bstrexlarge_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084000: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80084000);
    return;
    // 0x80084004: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bamovegoto_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080021C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800220: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800224: jal         0x8009B800
    // 0x80800228: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    baphysics_set_type(rdram, ctx);
        goto after_0;
    // 0x80800228: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x8080022C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800230: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800234: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x80800238: lbu         $t7, 0x55($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X55);
    // 0x8080023C: bne         $t7, $at, L_80800254
    if (ctx->r15 != ctx->r1) {
        // 0x80800240: nop
    
            goto L_80800254;
    }
    // 0x80800240: nop

    // 0x80800244: jal         0x80800000
    // 0x80800248: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800000_bamovegoto(rdram, ctx);
        goto after_1;
    // 0x80800248: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8080024C: b           L_80800260
    // 0x80800250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800260;
    // 0x80800250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800254:
    // 0x80800254: jal         0x80800000
    // 0x80800258: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800000_bamovegoto(rdram, ctx);
        goto after_2;
    // 0x80800258: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x8080025C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800260:
    // 0x80800260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800264: jr          $ra
    // 0x80800268: nop

    return;
    // 0x80800268: nop

;}
RECOMP_FUNC void func_80106314(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106314: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80106318: jr          $ra
    // 0x8010631C: lw          $v0, 0x6ED8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6ED8);
    return;
    // 0x8010631C: lw          $v0, 0x6ED8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6ED8);
;}
RECOMP_FUNC void func_8080329C_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080329C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808032A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808032A4: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x808032A8: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x808032AC: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x808032B0: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x808032B4: jal         0x80100094
    // 0x808032B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808032B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808032BC: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x808032C0: jal         0x800D674C
    // 0x808032C4: addiu       $a0, $zero, 0x829
    ctx->r4 = ADD32(0, 0X829);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x808032C4: addiu       $a0, $zero, 0x829
    ctx->r4 = ADD32(0, 0X829);
    after_1:
    // 0x808032C8: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x808032CC: jal         0x800D674C
    // 0x808032D0: addiu       $a0, $zero, 0x82A
    ctx->r4 = ADD32(0, 0X82A);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x808032D0: addiu       $a0, $zero, 0x82A
    ctx->r4 = ADD32(0, 0X82A);
    after_2:
    // 0x808032D4: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x808032D8: addiu       $a0, $zero, 0x829
    ctx->r4 = ADD32(0, 0X829);
    // 0x808032DC: jal         0x800D70F8
    // 0x808032E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D70F8(rdram, ctx);
        goto after_3;
    // 0x808032E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808032E4: addiu       $a0, $zero, 0x82A
    ctx->r4 = ADD32(0, 0X82A);
    // 0x808032E8: jal         0x800D70F8
    // 0x808032EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D70F8(rdram, ctx);
        goto after_4;
    // 0x808032EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808032F0: jal         0x80803224
    // 0x808032F4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80803224_chflysaucer(rdram, ctx);
        goto after_5;
    // 0x808032F4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_5:
    // 0x808032F8: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x808032FC: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80803300: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x80803304: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x80803308: jal         0x800EE7F8
    // 0x8080330C: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x8080330C: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    after_6:
    // 0x80803310: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80803314: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80803318: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8080331C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803320: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80803324: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80803328: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x8080332C: lbu         $v1, 0x24($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X24);
    // 0x80803330: beq         $v1, $at, L_80803414
    if (ctx->r3 == ctx->r1) {
        // 0x80803334: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80803414;
    }
    // 0x80803334: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80803338: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080333C: beq         $v0, $at, L_80803358
    if (ctx->r2 == ctx->r1) {
        // 0x80803340: lw          $t7, 0x6C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X6C);
            goto L_80803358;
    }
    // 0x80803340: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x80803344: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803348: beq         $v0, $at, L_80803414
    if (ctx->r2 == ctx->r1) {
        // 0x8080334C: nop
    
            goto L_80803414;
    }
    // 0x8080334C: nop

    // 0x80803350: b           L_808034E4
    // 0x80803354: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_808034E4;
    // 0x80803354: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80803358:
    // 0x80803358: beql        $t7, $zero, L_808034E4
    if (ctx->r15 == 0) {
        // 0x8080335C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808034E4;
    }
    goto skip_0;
    // 0x8080335C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80803360: jal         0x80104200
    // 0x80803364: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    func_80104200(rdram, ctx);
        goto after_7;
    // 0x80803364: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_7:
    // 0x80803368: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8080336C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80803370: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80803374: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80803378: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x8080337C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80803380: lui         $a3, 0x42D2
    ctx->r7 = S32(0X42D2 << 16);
    // 0x80803384: jal         0x800EF6A8
    // 0x80803388: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800EF6A8(rdram, ctx);
        goto after_8;
    // 0x80803388: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x8080338C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80803390: jal         0x800EF04C
    // 0x80803394: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    func_800EF04C(rdram, ctx);
        goto after_9;
    // 0x80803394: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    after_9:
    // 0x80803398: jal         0x8008B304
    // 0x8080339C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_8008B304(rdram, ctx);
        goto after_10;
    // 0x8080339C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_10:
    // 0x808033A0: jal         0x8008AEDC
    // 0x808033A4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_8008AEDC(rdram, ctx);
        goto after_11;
    // 0x808033A4: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_11:
    // 0x808033A8: jal         0x8008C27C
    // 0x808033AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008C27C(rdram, ctx);
        goto after_12;
    // 0x808033AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x808033B0: jal         0x800DF41C
    // 0x808033B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF41C(rdram, ctx);
        goto after_13;
    // 0x808033B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x808033B8: jal         0x800DF440
    // 0x808033BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF440(rdram, ctx);
        goto after_14;
    // 0x808033BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x808033C0: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x808033C4: lhu         $a0, 0x7A($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X7A);
    // 0x808033C8: srl         $t9, $a0, 14
    ctx->r25 = S32(U32(ctx->r4) >> 14);
    // 0x808033CC: jal         0x800DF830
    // 0x808033D0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800DF830(rdram, ctx);
        goto after_15;
    // 0x808033D0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_15:
    // 0x808033D4: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x808033D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4234) << 16);
    // 0x808033DC: lwc1        $f18, 0x4234($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4234));
    // 0x808033E0: lwc1        $f16, 0x38($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X38);
    // 0x808033E4: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x808033E8: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808033EC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808033F0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x808033F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808033F8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808033FC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80803400: jal         0x800DE448
    // 0x80803404: nop

    func_800DE448(rdram, ctx);
        goto after_16;
    // 0x80803404: nop

    after_16:
    // 0x80803408: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8080340C: b           L_808034E0
    // 0x80803410: lbu         $v1, 0x24($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X24);
        goto L_808034E0;
    // 0x80803410: lbu         $v1, 0x24($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X24);
L_80803414:
    // 0x80803414: beql        $t3, $zero, L_808034E4
    if (ctx->r11 == 0) {
        // 0x80803418: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808034E4;
    }
    goto skip_1;
    // 0x80803418: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x8080341C: jal         0x80104200
    // 0x80803420: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    func_80104200(rdram, ctx);
        goto after_17;
    // 0x80803420: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_17:
    // 0x80803424: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80803428: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080342C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80803430: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80803434: lwc1        $f6, 0x10($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X10);
    // 0x80803438: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8080343C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80803440: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80803444: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80803448: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x8080344C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80803450: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80803454: jal         0x800EF6A8
    // 0x80803458: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800EF6A8(rdram, ctx);
        goto after_18;
    // 0x80803458: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_18:
    // 0x8080345C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80803460: jal         0x800EF04C
    // 0x80803464: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    func_800EF04C(rdram, ctx);
        goto after_19;
    // 0x80803464: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    after_19:
    // 0x80803468: jal         0x8008B304
    // 0x8080346C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_8008B304(rdram, ctx);
        goto after_20;
    // 0x8080346C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_20:
    // 0x80803470: jal         0x8008AEDC
    // 0x80803474: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_8008AEDC(rdram, ctx);
        goto after_21;
    // 0x80803474: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_21:
    // 0x80803478: jal         0x8008C27C
    // 0x8080347C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008C27C(rdram, ctx);
        goto after_22;
    // 0x8080347C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_22:
    // 0x80803480: jal         0x800DF41C
    // 0x80803484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF41C(rdram, ctx);
        goto after_23;
    // 0x80803484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x80803488: jal         0x800DF440
    // 0x8080348C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF440(rdram, ctx);
        goto after_24;
    // 0x8080348C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_24:
    // 0x80803490: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80803494: lhu         $a0, 0x7A($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X7A);
    // 0x80803498: srl         $t6, $a0, 14
    ctx->r14 = S32(U32(ctx->r4) >> 14);
    // 0x8080349C: jal         0x800DF830
    // 0x808034A0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800DF830(rdram, ctx);
        goto after_25;
    // 0x808034A0: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_25:
    // 0x808034A4: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x808034A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4238) << 16);
    // 0x808034AC: lwc1        $f4, 0x4238($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4238));
    // 0x808034B0: lwc1        $f18, 0x38($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X38);
    // 0x808034B4: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x808034B8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808034BC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808034C0: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x808034C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808034C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808034CC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808034D0: jal         0x800DE448
    // 0x808034D4: nop

    func_800DE448(rdram, ctx);
        goto after_26;
    // 0x808034D4: nop

    after_26:
    // 0x808034D8: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x808034DC: lbu         $v1, 0x24($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X24);
L_808034E0:
    // 0x808034E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_808034E4:
    // 0x808034E4: bne         $v1, $at, L_8080359C
    if (ctx->r3 != ctx->r1) {
        // 0x808034E8: lw          $t0, 0x70($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X70);
            goto L_8080359C;
    }
    // 0x808034E8: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x808034EC: beql        $t0, $zero, L_808035A0
    if (ctx->r8 == 0) {
        // 0x808034F0: addiu       $a0, $zero, 0x829
        ctx->r4 = ADD32(0, 0X829);
            goto L_808035A0;
    }
    goto skip_2;
    // 0x808034F0: addiu       $a0, $zero, 0x829
    ctx->r4 = ADD32(0, 0X829);
    skip_2:
    // 0x808034F4: jal         0x80104200
    // 0x808034F8: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    func_80104200(rdram, ctx);
        goto after_27;
    // 0x808034F8: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    after_27:
    // 0x808034FC: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80803500: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80803504: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80803508: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8080350C: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x80803510: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80803514: lui         $a3, 0x42D2
    ctx->r7 = S32(0X42D2 << 16);
    // 0x80803518: jal         0x800EF6A8
    // 0x8080351C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800EF6A8(rdram, ctx);
        goto after_28;
    // 0x8080351C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_28:
    // 0x80803520: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80803524: jal         0x800EF04C
    // 0x80803528: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    func_800EF04C(rdram, ctx);
        goto after_29;
    // 0x80803528: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    after_29:
    // 0x8080352C: jal         0x8008B304
    // 0x80803530: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8008B304(rdram, ctx);
        goto after_30;
    // 0x80803530: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_30:
    // 0x80803534: jal         0x8008AEDC
    // 0x80803538: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8008AEDC(rdram, ctx);
        goto after_31;
    // 0x80803538: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_31:
    // 0x8080353C: jal         0x8008C27C
    // 0x80803540: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008C27C(rdram, ctx);
        goto after_32;
    // 0x80803540: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_32:
    // 0x80803544: jal         0x800DF41C
    // 0x80803548: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF41C(rdram, ctx);
        goto after_33;
    // 0x80803548: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_33:
    // 0x8080354C: jal         0x800DF440
    // 0x80803550: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF440(rdram, ctx);
        goto after_34;
    // 0x80803550: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_34:
    // 0x80803554: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80803558: lhu         $a0, 0x7A($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X7A);
    // 0x8080355C: srl         $t2, $a0, 14
    ctx->r10 = S32(U32(ctx->r4) >> 14);
    // 0x80803560: jal         0x800DF830
    // 0x80803564: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_800DF830(rdram, ctx);
        goto after_35;
    // 0x80803564: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_35:
    // 0x80803568: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x8080356C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X423C) << 16);
    // 0x80803570: lwc1        $f16, 0x423C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X423C));
    // 0x80803574: lwc1        $f10, 0x38($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X38);
    // 0x80803578: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x8080357C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80803580: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80803584: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80803588: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080358C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80803590: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80803594: jal         0x800DE448
    // 0x80803598: nop

    func_800DE448(rdram, ctx);
        goto after_36;
    // 0x80803598: nop

    after_36:
L_8080359C:
    // 0x8080359C: addiu       $a0, $zero, 0x829
    ctx->r4 = ADD32(0, 0X829);
L_808035A0:
    // 0x808035A0: jal         0x800D70F8
    // 0x808035A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D70F8(rdram, ctx);
        goto after_37;
    // 0x808035A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_37:
    // 0x808035A8: addiu       $a0, $zero, 0x82A
    ctx->r4 = ADD32(0, 0X82A);
    // 0x808035AC: jal         0x800D70F8
    // 0x808035B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D70F8(rdram, ctx);
        goto after_38;
    // 0x808035B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_38:
    // 0x808035B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808035B8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x808035BC: jr          $ra
    // 0x808035C0: nop

    return;
    // 0x808035C0: nop

;}
RECOMP_FUNC void trangler_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080014C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800150: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800154: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800158: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080015C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800160: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800164: jal         0x8010E810
    // 0x80800168: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_8010E810(rdram, ctx);
        goto after_0;
    // 0x80800168: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080016C: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x80800170: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800174: jal         0x800DF8D4
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DF8D4(rdram, ctx);
        goto after_1;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080017C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800180: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: addiu       $t6, $v1, 0x1C
    ctx->r14 = ADD32(ctx->r3, 0X1C);
    // 0x8080018C: sra         $a1, $t0, 16
    ctx->r5 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80800190: andi        $t7, $a1, 0xFFFF
    ctx->r15 = ctx->r5 & 0XFFFF;
    // 0x80800194: sb          $v0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r2;
    // 0x80800198: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
    // 0x8080019C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x808001A0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x808001A4: jal         0x80800000
    // 0x808001A8: andi        $a2, $t0, 0xFFFF
    ctx->r6 = ctx->r8 & 0XFFFF;
    func_80800000_trangler(rdram, ctx);
        goto after_2;
    // 0x808001A8: andi        $a2, $t0, 0xFFFF
    ctx->r6 = ctx->r8 & 0XFFFF;
    after_2:
    // 0x808001AC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x808001B0: jal         0x800C87B8
    // 0x808001B4: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    func_800C87B8(rdram, ctx);
        goto after_3;
    // 0x808001B4: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    after_3:
    // 0x808001B8: jal         0x800DF8B4
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DF8B4(rdram, ctx);
        goto after_4;
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001C0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808001C4: jal         0x800DF8CC
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DF8CC(rdram, ctx);
        goto after_5;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808001CC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808001D0: jal         0x800DF8BC
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DF8BC(rdram, ctx);
        goto after_6;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001DC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808001E0: jal         0x8010EBE4
    // 0x808001E4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_8010EBE4(rdram, ctx);
        goto after_7;
    // 0x808001E4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_7:
    // 0x808001E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

    // 0x808001FC: nop

;}
RECOMP_FUNC void func_80090684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009068C: jal         0x800F54E4
    // 0x80090690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090690: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80090694: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80090698: jal         0x800F8200
    // 0x8009069C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F8200(rdram, ctx);
        goto after_1;
    // 0x8009069C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800906A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800906A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800906A8: jr          $ra
    // 0x800906AC: nop

    return;
    // 0x800906AC: nop

;}
RECOMP_FUNC void func_80801770_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801778: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080177C: lw          $t7, 0x188($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X188);
    // 0x80801780: jal         0x80087278
    // 0x80801784: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    _chfaircoinbox_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801784: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x80801788: jal         0x808000F0
    // 0x8080178C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsvan_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080178C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801798: jr          $ra
    // 0x8080179C: nop

    return;
    // 0x8080179C: nop

;}
RECOMP_FUNC void bsbegghead_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808002B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(87, 0X2E0) << 16);
    // 0x808002B8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808002BC: jr          $ra
    // 0x808002C0: lw          $v0, 0x2E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(87, 0X2E0));
    return;
    // 0x808002C0: lw          $v0, 0x2E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(87, 0X2E0));
;}
RECOMP_FUNC void func_8009C1CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C1CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C1D0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8009C1D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C1D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8009C1DC: lw          $a1, 0xE4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XE4);
    // 0x8009C1E0: jal         0x800EE7F8
    // 0x8009C1E4: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009C1E4: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    after_0:
    // 0x8009C1E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C1EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C1F0: jr          $ra
    // 0x8009C1F4: nop

    return;
    // 0x8009C1F4: nop

;}
RECOMP_FUNC void cadbmgrDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C8: jal         0x800A56A4
    // 0x808000CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A56A4(rdram, ctx);
        goto after_0;
    // 0x808000CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000D0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808000D4: jal         0x8001B084
    // 0x808000D8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    heap_free(rdram, ctx);
        goto after_1;
    // 0x808000D8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x808000DC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x808000E0: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

;}
RECOMP_FUNC void func_80800508_chcrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800508: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080050C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800510: lwc1        $f18, 0x20($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80800514: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80800518: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8080051C: lwc1        $f12, 0x18($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80800520: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80800524: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800528: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080052C: sub.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x80800530: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800534: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800538: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8080053C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800540: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x80800544: jal         0x8010D254
    // 0x80800548: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80800548: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8080054C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80800550: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800554: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800558: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8080055C: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800560: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800564: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80800568: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080056C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800570: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80800574: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80800578: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8080057C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80800580: lwc1        $f10, 0x1C($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x80800584: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x80800588: lwc1        $f16, 0x1C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x8080058C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800590: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80800594: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80800598: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8080059C: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x808005A0: lwc1        $f10, 0xC($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XC);
    // 0x808005A4: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x808005A8: jal         0x8008FA94
    // 0x808005AC: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    func_8008FA94(rdram, ctx);
        goto after_1;
    // 0x808005AC: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x808005B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808005B8: jr          $ra
    // 0x808005BC: nop

    return;
    // 0x808005BC: nop

;}
RECOMP_FUNC void func_800C7B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7B7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C7B80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C7B84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C7B88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C7B8C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C7B90: jal         0x800C7980
    // 0x800C7B94: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800C7980(rdram, ctx);
        goto after_0;
    // 0x800C7B94: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800C7B98: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800C7B9C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C7BA0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800C7BA4: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x800C7BA8: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800C7BAC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800C7BB0: addiu       $a1, $v1, 0x14
    ctx->r5 = ADD32(ctx->r3, 0X14);
    // 0x800C7BB4: jal         0x80089140
    // 0x800C7BB8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _mlspline_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x800C7BB8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800C7BBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7BC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C7BC4: jr          $ra
    // 0x800C7BC8: nop

    return;
    // 0x800C7BC8: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800894C8: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x800894C8);
    return;
    // 0x800894CC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsblongleg_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800829F0: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x800829F0);
    return;
    // 0x800829F4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085630: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085630);
    return;
    // 0x80085634: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void fxripple_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001F8: jal         0x80800094
    // 0x808001FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800094_fxripple(rdram, ctx);
        goto after_0;
    // 0x808001FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800204: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800208: jr          $ra
    // 0x8080020C: nop

    return;
    // 0x8080020C: nop

;}
RECOMP_FUNC void _gsmaker_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800825B0: syscall     2
    recomp_syscall_handler(rdram, ctx, 0x800825B0);
    return;
    // 0x800825B4: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_80800020_ncbasuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800028: jal         0x80112524
    // 0x8080002C: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x8080002C: nop

    after_0:
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void _bsrest_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800839C8: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x800839C8);
    return;
    // 0x800839CC: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void _gcegg_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883D8: syscall     680
    recomp_syscall_handler(rdram, ctx, 0x800883D8);
    return;
    // 0x800883DC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
