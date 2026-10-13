#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800100_chjujubagfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800104: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800108: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080010C: jal         0x8010D278
    // 0x80800110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8010D278(rdram, ctx);
        goto after_0;
    // 0x80800110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800114: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80800118: beq         $v0, $at, L_80800140
    if (ctx->r2 == ctx->r1) {
        // 0x8080011C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800140;
    }
    // 0x8080011C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800120: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800124: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // 0x80800128: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8080012C: jal         0x80089C20
    // 0x80800130: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800130: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80800134: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800138: b           L_80800148
    // 0x8080013C: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
        goto L_80800148;
    // 0x8080013C: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
L_80800140:
    // 0x80800140: jal         0x8008FE94
    // 0x80800144: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_8008FE94(rdram, ctx);
        goto after_2;
    // 0x80800144: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
L_80800148:
    // 0x80800148: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800154: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x80800158: jal         0x8080000C
    // 0x8080015C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_8080000C_chjujubagfx(rdram, ctx);
        goto after_3;
    // 0x8080015C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_3:
    // 0x80800160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800164: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800168: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080016C: jr          $ra
    // 0x80800170: nop

    return;
    // 0x80800170: nop

;}
RECOMP_FUNC void func_80801114_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080111C: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x80801120: bgtz        $v0, L_80801130
    if (SIGNED(ctx->r2) > 0) {
        // 0x80801124: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80801130;
    }
    // 0x80801124: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80801128: b           L_80801180
    // 0x8080112C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801180;
    // 0x8080112C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801130:
    // 0x80801130: sh          $t6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r14;
    // 0x80801134: lh          $a1, 0x6($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X6);
    // 0x80801138: jal         0x80800038
    // 0x8080113C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800038_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x8080113C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801140: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801144: bne         $v0, $at, L_8080117C
    if (ctx->r2 != ctx->r1) {
        // 0x80801148: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080117C;
    }
    // 0x80801148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080114C: lh          $t9, 0xA($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XA);
    // 0x80801150: lh          $t7, 0x8($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X8);
    // 0x80801154: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80801158: sh          $t0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r8;
    // 0x8080115C: lh          $t1, 0xA($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XA);
    // 0x80801160: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80801164: sh          $t8, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r24;
    // 0x80801168: bgezl       $t1, L_80801180
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8080116C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801180;
    }
    goto skip_0;
    // 0x8080116C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80801170: lh          $t2, 0x2($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2);
    // 0x80801174: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80801178: sh          $t3, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r11;
L_8080117C:
    // 0x8080117C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801180:
    // 0x80801180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801188: jr          $ra
    // 0x8080118C: nop

    return;
    // 0x8080118C: nop

;}
RECOMP_FUNC void _chevilmumbo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086BC0: syscall     426
    recomp_syscall_handler(rdram, ctx, 0x80086BC0);
    return;
    // 0x80086BC4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _baduo_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800849B0: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x800849B0);
    return;
    // 0x800849B4: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_800BFB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFB58: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800BFB5C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800BFB60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BFB64: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800BFB68: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800BFB6C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800BFB70: jal         0x800BFC94
    // 0x800BFB74: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    func_800BFC94(rdram, ctx);
        goto after_0;
    // 0x800BFB74: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800BFB78: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800BFB7C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800BFB80: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800BFB84: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800BFB88: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800BFB8C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800BFB90: jal         0x800EFA4C
    // 0x800BFB94: nop

    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x800BFB94: nop

    after_1:
    // 0x800BFB98: jal         0x800D2F20
    // 0x800BFB9C: nop

    func_800D2F20(rdram, ctx);
        goto after_2;
    // 0x800BFB9C: nop

    after_2:
    // 0x800BFBA0: jal         0x800E249C
    // 0x800BFBA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E249C(rdram, ctx);
        goto after_3;
    // 0x800BFBA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800BFBA8: jal         0x800E24C0
    // 0x800BFBAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E24C0(rdram, ctx);
        goto after_4;
    // 0x800BFBAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x800BFBB0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800BFBB4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800BFBB8: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800BFBBC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800BFBC0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800BFBC4: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800BFBC8: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800BFBCC: subu        $a2, $v0, $t1
    ctx->r6 = SUB32(ctx->r2, ctx->r9);
    // 0x800BFBD0: subu        $a1, $v0, $t9
    ctx->r5 = SUB32(ctx->r2, ctx->r25);
    // 0x800BFBD4: jal         0x800E24F8
    // 0x800BFBD8: subu        $a0, $v0, $t7
    ctx->r4 = SUB32(ctx->r2, ctx->r15);
    func_800E24F8(rdram, ctx);
        goto after_5;
    // 0x800BFBD8: subu        $a0, $v0, $t7
    ctx->r4 = SUB32(ctx->r2, ctx->r15);
    after_5:
    // 0x800BFBDC: jal         0x800AF5A8
    // 0x800BFBE0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800AF5A8(rdram, ctx);
        goto after_6;
    // 0x800BFBE0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x800BFBE4: andi        $t2, $v0, 0xB00
    ctx->r10 = ctx->r2 & 0XB00;
    // 0x800BFBE8: beq         $t2, $zero, L_800BFBF8
    if (ctx->r10 == 0) {
        // 0x800BFBEC: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_800BFBF8;
    }
    // 0x800BFBEC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800BFBF0: b           L_800BFBF8
    // 0x800BFBF4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800BFBF8;
    // 0x800BFBF4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800BFBF8:
    // 0x800BFBF8: jal         0x800E2588
    // 0x800BFBFC: nop

    func_800E2588(rdram, ctx);
        goto after_7;
    // 0x800BFBFC: nop

    after_7:
    // 0x800BFC00: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x800BFC04: addiu       $t4, $sp, 0x2C
    ctx->r12 = ADD32(ctx->r29, 0X2C);
    // 0x800BFC08: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800BFC0C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800BFC10: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800BFC14: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800BFC18: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x800BFC1C: jal         0x800E2AA4
    // 0x800BFC20: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_800E2AA4(rdram, ctx);
        goto after_8;
    // 0x800BFC20: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_8:
    // 0x800BFC24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BFC28: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800BFC2C: jr          $ra
    // 0x800BFC30: nop

    return;
    // 0x800BFC30: nop

;}
RECOMP_FUNC void func_80800E64_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E6C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800E70: lbu         $a1, 0x5E($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X5E);
    // 0x80800E74: addiu       $a0, $zero, 0xC7
    ctx->r4 = ADD32(0, 0XC7);
    // 0x80800E78: jal         0x800D2498
    // 0x80800E7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_0;
    // 0x80800E7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800E80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E88: jr          $ra
    // 0x80800E8C: nop

    return;
    // 0x80800E8C: nop

;}
RECOMP_FUNC void _bswalk_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084260: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084260);
    return;
    // 0x80084264: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_80800000_chfaircoinbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800004: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2132, 0X424) << 16);
    // 0x80800008: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080000C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80800010: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80800014: jr          $ra
    // 0x80800018: lh          $v0, 0x424($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(2132, 0X424));
    return;
    // 0x80800018: lh          $v0, 0x424($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(2132, 0X424));
;}
RECOMP_FUNC void func_80800030_chminegrill2switches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800034: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080003C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800040: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800044: bne         $a1, $at, L_80800074
    if (ctx->r5 != ctx->r1) {
        // 0x80800048: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800074;
    }
    // 0x80800048: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080004C: addiu       $a0, $zero, 0x4C2
    ctx->r4 = ADD32(0, 0X4C2);
    // 0x80800050: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800054: jal         0x80101180
    // 0x80800058: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x80800058: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8080005C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800060: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800064: jal         0x80085820
    // 0x80800068: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800068: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080006C: b           L_80800088
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800088;
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800074:
    // 0x80800074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800078: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080007C: jal         0x80085820
    // 0x80800080: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x80800080: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
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
RECOMP_FUNC void _gcstatusDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088340: syscall     679
    recomp_syscall_handler(rdram, ctx, 0x80088340);
    return;
    // 0x80088344: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_808000A8_chhellterskelter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000B4: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808000B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000BC: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x808000C0: bgez        $t8, L_80800110
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808000C4: nop
    
            goto L_80800110;
    }
    // 0x808000C4: nop

    // 0x808000C8: jal         0x800DA298
    // 0x808000CC: addiu       $a0, $zero, 0xA4B
    ctx->r4 = ADD32(0, 0XA4B);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808000CC: addiu       $a0, $zero, 0xA4B
    ctx->r4 = ADD32(0, 0XA4B);
    after_0:
    // 0x808000D0: bne         $v0, $zero, L_80800110
    if (ctx->r2 != 0) {
        // 0x808000D4: addiu       $a0, $zero, 0x6A2
        ctx->r4 = ADD32(0, 0X6A2);
            goto L_80800110;
    }
    // 0x808000D4: addiu       $a0, $zero, 0x6A2
    ctx->r4 = ADD32(0, 0X6A2);
    // 0x808000D8: jal         0x800DA9E4
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_1;
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000E0: bne         $v0, $zero, L_808000F8
    if (ctx->r2 != 0) {
        // 0x808000E4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808000F8;
    }
    // 0x808000E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808000EC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808000F0: jal         0x80085708
    // 0x808000F4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x808000F4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
L_808000F8:
    // 0x808000F8: jal         0x800857A0
    // 0x808000FC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    _chshockjump_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808000FC: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_3:
    // 0x80800100: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80800104: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80800108: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x8080010C: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
L_80800110:
    // 0x80800110: jal         0x800D90A4
    // 0x80800114: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_4;
    // 0x80800114: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_4:
    // 0x80800118: beq         $v0, $zero, L_80800144
    if (ctx->r2 == 0) {
        // 0x8080011C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800144;
    }
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: jal         0x80108B04
    // 0x80800124: addiu       $a1, $zero, 0x33A
    ctx->r5 = ADD32(0, 0X33A);
    func_80108B04(rdram, ctx);
        goto after_5;
    // 0x80800124: addiu       $a1, $zero, 0x33A
    ctx->r5 = ADD32(0, 0X33A);
    after_5:
    // 0x80800128: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8080012C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800130: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800134: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800138: jal         0x800DC178
    // 0x8080013C: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x8080013C: nop

    after_6:
    // 0x80800140: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80800144:
    // 0x80800144: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800148: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080014C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800150: jr          $ra
    // 0x80800154: nop

    return;
    // 0x80800154: nop

;}
RECOMP_FUNC void bskazdie_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800260: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800264: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800268: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080026C: jal         0x8008CABC
    // 0x80800270: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800270: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800274: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800278: jal         0x80085260
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: jal         0x8009B9B0
    // 0x80800288: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800288: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_2:
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: jal         0x8009D3A8
    // 0x80800294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_3;
    // 0x80800294: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800298: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x8080029C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: beq         $v0, $zero, L_808002C4
    if (ctx->r2 == 0) {
        // 0x808002A8: nop
    
            goto L_808002C4;
    }
    // 0x808002A8: nop

    // 0x808002AC: beq         $v0, $at, L_8080033C
    if (ctx->r2 == ctx->r1) {
        // 0x808002B0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080033C;
    }
    // 0x808002B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808002B4: beql        $v0, $at, L_808003BC
    if (ctx->r2 == ctx->r1) {
        // 0x808002B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003BC;
    }
    goto skip_0;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808002BC: b           L_808003BC
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808003BC;
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002C4:
    // 0x808002C4: jal         0x8008DF8C
    // 0x808002C8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_4;
    // 0x808002C8: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_4:
    // 0x808002CC: beq         $v0, $zero, L_808003B8
    if (ctx->r2 == 0) {
        // 0x808002D0: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_808003B8;
    }
    // 0x808002D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808002D4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808002D8: jal         0x8008B1D4
    // 0x808002DC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_5;
    // 0x808002DC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
    // 0x808002E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808002E4: jal         0x8008B134
    // 0x808002E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x808002E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F0: jal         0x8009BA58
    // 0x808002F4: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_7;
    // 0x808002F4: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_7:
    // 0x808002F8: jal         0x8009E058
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E058(rdram, ctx);
        goto after_8;
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800300: jal         0x8009D9D4
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D9D4(rdram, ctx);
        goto after_9;
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800308: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080030C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800310: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800314: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800318: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080031C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800320: jal         0x80085490
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamotor_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800328: jal         0x80800000
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskazdie(rdram, ctx);
        goto after_11;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800330: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800334: b           L_808003B8
    // 0x80800338: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_808003B8;
    // 0x80800338: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_8080033C:
    // 0x8080033C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80800340: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800344: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800348: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080034C: jal         0x800F0E00
    // 0x80800350: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_800F0E00(rdram, ctx);
        goto after_12;
    // 0x80800350: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_12:
    // 0x80800354: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80800358: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080035C: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x80800360: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800364: nop

    // 0x80800368: bc1fl       L_8080037C
    if (!c1cs) {
        // 0x8080036C: lui         $a1, 0x3F27
        ctx->r5 = S32(0X3F27 << 16);
            goto L_8080037C;
    }
    goto skip_1;
    // 0x8080036C: lui         $a1, 0x3F27
    ctx->r5 = S32(0X3F27 << 16);
    skip_1:
    // 0x80800370: jal         0x80084A10
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_9(rdram, ctx);
        goto after_13;
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800378: lui         $a1, 0x3F27
    ctx->r5 = S32(0X3F27 << 16);
L_8080037C:
    // 0x8080037C: ori         $a1, $a1, 0x5F70
    ctx->r5 = ctx->r5 | 0X5F70;
    // 0x80800380: jal         0x8008B348
    // 0x80800384: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isAt(rdram, ctx);
        goto after_14;
    // 0x80800384: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_14:
    // 0x80800388: beq         $v0, $zero, L_80800398
    if (ctx->r2 == 0) {
        // 0x8080038C: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800398;
    }
    // 0x8080038C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800390: jal         0x8008B1BC
    // 0x80800394: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_15;
    // 0x80800394: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_15:
L_80800398:
    // 0x80800398: jal         0x8008B324
    // 0x8080039C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_isStopped(rdram, ctx);
        goto after_16;
    // 0x8080039C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_16:
    // 0x808003A0: beql        $v0, $zero, L_808003BC
    if (ctx->r2 == 0) {
        // 0x808003A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003BC;
    }
    goto skip_2;
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808003A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808003AC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x808003B0: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
    // 0x808003B4: swc1        $f10, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f10.u32l;
L_808003B8:
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003BC:
    // 0x808003BC: jal         0x800852F0
    // 0x808003C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_17;
    // 0x808003C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x808003C4: beql        $v0, $zero, L_808003D8
    if (ctx->r2 == 0) {
        // 0x808003C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D8;
    }
    goto skip_3;
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x808003CC: jal         0x80085200
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basudie_entrypoint_0(rdram, ctx);
        goto after_18;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003D8:
    // 0x808003D8: jal         0x8009E5C8
    // 0x808003DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bs_setState(rdram, ctx);
        goto after_19;
    // 0x808003DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x808003E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003EC: jr          $ra
    // 0x808003F0: nop

    return;
    // 0x808003F0: nop

;}
RECOMP_FUNC void func_80105B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105B0C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80105B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105B14: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80105B18: jal         0x80105494
    // 0x80105B1C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x80105B1C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80105B20: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80105B24: jal         0x800D7DE8
    // 0x80105B28: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800D7DE8(rdram, ctx);
        goto after_1;
    // 0x80105B28: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x80105B2C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80105B30: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80105B34: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80105B38: sll         $t7, $a0, 21
    ctx->r15 = S32(ctx->r4 << 21);
    // 0x80105B3C: jal         0x800D7520
    // 0x80105B40: sra         $a0, $t7, 22
    ctx->r4 = S32(SIGNED(ctx->r15) >> 22);
    func_800D7520(rdram, ctx);
        goto after_2;
    // 0x80105B40: sra         $a0, $t7, 22
    ctx->r4 = S32(SIGNED(ctx->r15) >> 22);
    after_2:
    // 0x80105B44: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80105B48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80105B4C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80105B50: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x80105B54: jal         0x800C810C
    // 0x80105B58: lw          $a1, 0xC($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC);
    func_800C810C(rdram, ctx);
        goto after_3;
    // 0x80105B58: lw          $a1, 0xC($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC);
    after_3:
    // 0x80105B5C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80105B60: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80105B64: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80105B68: andi        $t1, $t0, 0x100
    ctx->r9 = ctx->r8 & 0X100;
    // 0x80105B6C: beq         $t1, $zero, L_80105BA4
    if (ctx->r9 == 0) {
        // 0x80105B70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80105BA4;
    }
    // 0x80105B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105B74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80105B78: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80105B7C: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x80105B80: nop

    // 0x80105B84: bc1fl       L_80105B9C
    if (!c1cs) {
        // 0x80105B88: add.s       $f2, $f12, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_80105B9C;
    }
    goto skip_0;
    // 0x80105B88: add.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f0.fl;
    skip_0:
    // 0x80105B8C: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80105B90: b           L_80105BA4
    // 0x80105B94: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80105BA4;
    // 0x80105B94: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80105B98: add.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f0.fl;
L_80105B9C:
    // 0x80105B9C: b           L_80105BA4
    // 0x80105BA0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80105BA4;
    // 0x80105BA0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80105BA4:
    // 0x80105BA4: jr          $ra
    // 0x80105BA8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80105BA8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _chfirefx_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086148: syscall     281
    recomp_syscall_handler(rdram, ctx, 0x80086148);
    return;
    // 0x8008614C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800000_bsbwhirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
    return;
    // 0x80800004: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80800168_bsbflap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x8080016C: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80800170: beq         $at, $zero, L_808001C8
    if (ctx->r1 == 0) {
        // 0x80800174: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808001C8;
    }
    // 0x80800174: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800178: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(90, 0X6F0) << 16);
    // 0x8080017C: addu        $at, $at, $t6
    gpr jr_addend_80800184 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800180: lw          $t6, 0x6F0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(90, 0X6F0));
    // 0x80800184: jr          $t6
    // 0x80800188: nop

    switch (jr_addend_80800184 >> 2) {
        case 0: goto L_8080018C; break;
        case 1: goto L_80800198; break;
        case 2: goto L_808001A4; break;
        case 3: goto L_808001B0; break;
        case 4: goto L_808001BC; break;
        default: switch_error(__func__, 0x80800184, 0x808006F0);
    }
    // 0x80800188: nop

L_8080018C:
    // 0x8080018C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(90, 0X704) << 16);
    // 0x80800190: jr          $ra
    // 0x80800194: lwc1        $f0, 0x704($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X704));
    return;
    // 0x80800194: lwc1        $f0, 0x704($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X704));
L_80800198:
    // 0x80800198: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(90, 0X708) << 16);
    // 0x8080019C: jr          $ra
    // 0x808001A0: lwc1        $f0, 0x708($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X708));
    return;
    // 0x808001A0: lwc1        $f0, 0x708($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X708));
L_808001A4:
    // 0x808001A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(90, 0X70C) << 16);
    // 0x808001A8: jr          $ra
    // 0x808001AC: lwc1        $f0, 0x70C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X70C));
    return;
    // 0x808001AC: lwc1        $f0, 0x70C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X70C));
L_808001B0:
    // 0x808001B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(90, 0X710) << 16);
    // 0x808001B4: jr          $ra
    // 0x808001B8: lwc1        $f0, 0x710($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X710));
    return;
    // 0x808001B8: lwc1        $f0, 0x710($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X710));
L_808001BC:
    // 0x808001BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(90, 0X714) << 16);
    // 0x808001C0: jr          $ra
    // 0x808001C4: lwc1        $f0, 0x714($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X714));
    return;
    // 0x808001C4: lwc1        $f0, 0x714($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X714));
L_808001C8:
    // 0x808001C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(90, 0X718) << 16);
    // 0x808001CC: lwc1        $f0, 0x718($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(90, 0X718));
    // 0x808001D0: jr          $ra
    // 0x808001D4: nop

    return;
    // 0x808001D4: nop

;}
RECOMP_FUNC void func_800E8C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8C60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E8C64: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800E8C68: jal         0x800E8CB0
    // 0x800E8C6C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800E8CB0(rdram, ctx);
        goto after_0;
    // 0x800E8C6C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x800E8C70: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x800E8C74: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800E8C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8C7C: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x800E8C80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8C84: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E8C88: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800E8C8C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800E8C90: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800E8C94: nop

    // 0x800E8C98: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800E8C9C: bne         $at, $zero, L_800E8CA8
    if (ctx->r1 != 0) {
        // 0x800E8CA0: nop
    
            goto L_800E8CA8;
    }
    // 0x800E8CA0: nop

    // 0x800E8CA4: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
L_800E8CA8:
    // 0x800E8CA8: jr          $ra
    // 0x800E8CAC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800E8CAC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void badrone_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x80800050: jr          $ra
    // 0x80800054: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    return;
    // 0x80800054: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
;}
RECOMP_FUNC void func_800BA1D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA1D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BA1D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BA1D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BA1DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800BA1E0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800BA1E4: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800BA1E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800BA1EC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x800BA1F0: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x800BA1F4: jal         0x800EE940
    // 0x800BA1F8: sh          $t7, -0x28($a0)
    MEM_H(-0X28, ctx->r4) = ctx->r15;
    func_800EE940(rdram, ctx);
        goto after_0;
    // 0x800BA1F8: sh          $t7, -0x28($a0)
    MEM_H(-0X28, ctx->r4) = ctx->r15;
    after_0:
    // 0x800BA1FC: addiu       $a0, $s0, 0x2E
    ctx->r4 = ADD32(ctx->r16, 0X2E);
    // 0x800BA200: jal         0x800EE940
    // 0x800BA204: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE940(rdram, ctx);
        goto after_1;
    // 0x800BA204: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x800BA208: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x800BA20C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800BA210: jal         0x800BA22C
    // 0x800BA214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BA22C(rdram, ctx);
        goto after_2;
    // 0x800BA214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800BA218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA21C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BA220: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BA224: jr          $ra
    // 0x800BA228: nop

    return;
    // 0x800BA228: nop

;}
RECOMP_FUNC void bsclimb_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808005B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005C0: jal         0x800956B8
    // 0x808005C4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    func_800956B8(rdram, ctx);
        goto after_0;
    // 0x808005C4: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_0:
    // 0x808005C8: jal         0x8080005C
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080005C_bsclimb(rdram, ctx);
        goto after_1;
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D4: jal         0x8008CB10
    // 0x808005D8: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x808005D8: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_2:
    // 0x808005DC: beq         $v0, $zero, L_808005EC
    if (ctx->r2 == 0) {
        // 0x808005E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005EC;
    }
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E4: jal         0x80800000
    // 0x808005E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800000_bsclimb(rdram, ctx);
        goto after_3;
    // 0x808005E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_808005EC:
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F0: jal         0x8008CB10
    // 0x808005F4: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x808005F4: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_4:
    // 0x808005F8: beq         $v0, $zero, L_80800608
    if (ctx->r2 == 0) {
        // 0x808005FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800608;
    }
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800600: jal         0x80800000
    // 0x80800604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_bsclimb(rdram, ctx);
        goto after_5;
    // 0x80800604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_80800608:
    // 0x80800608: jal         0x80800298
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800298_bsclimb(rdram, ctx);
        goto after_6;
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800610: bnel        $v0, $zero, L_80800644
    if (ctx->r2 != 0) {
        // 0x80800614: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800644;
    }
    goto skip_0;
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800618: jal         0x8009BB50
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_7;
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800620: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800624: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800628: addiu       $t6, $zero, 0x4F
    ctx->r14 = ADD32(0, 0X4F);
    // 0x8080062C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800630: nop

    // 0x80800634: bc1fl       L_80800644
    if (!c1cs) {
        // 0x80800638: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800644;
    }
    goto skip_1;
    // 0x80800638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8080063C: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800644:
    // 0x80800644: jal         0x8009C128
    // 0x80800648: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8009C128(rdram, ctx);
        goto after_8;
    // 0x80800648: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_8:
    // 0x8080064C: jal         0x8009BB0C
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB0C(rdram, ctx);
        goto after_9;
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800654: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800658: nop

    // 0x8080065C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800660: nop

    // 0x80800664: bc1f        L_80800690
    if (!c1cs) {
        // 0x80800668: nop
    
            goto L_80800690;
    }
    // 0x80800668: nop

    // 0x8080066C: jal         0x800985B8
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800985B8(rdram, ctx);
        goto after_10;
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800674: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800678: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080067C: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80800680: nop

    // 0x80800684: bc1f        L_80800690
    if (!c1cs) {
        // 0x80800688: nop
    
            goto L_80800690;
    }
    // 0x80800688: nop

    // 0x8080068C: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
L_80800690:
    // 0x80800690: jal         0x80098640
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80098640(rdram, ctx);
        goto after_11;
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800698: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080069C: bnel        $v0, $at, L_80800710
    if (ctx->r2 != ctx->r1) {
        // 0x808006A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800710;
    }
    goto skip_2;
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808006A4: jal         0x8009BB0C
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB0C(rdram, ctx);
        goto after_12;
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808006AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808006B0: nop

    // 0x808006B4: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x808006B8: nop

    // 0x808006BC: bc1fl       L_80800710
    if (!c1cs) {
        // 0x808006C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800710;
    }
    goto skip_3;
    // 0x808006C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x808006C4: jal         0x8009864C
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009864C(rdram, ctx);
        goto after_13;
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808006CC: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D4: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x808006D8: nop

    // 0x808006DC: bc1fl       L_80800710
    if (!c1cs) {
        // 0x808006E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800710;
    }
    goto skip_4;
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x808006E4: jal         0x800985C4
    // 0x808006E8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800985C4(rdram, ctx);
        goto after_14;
    // 0x808006E8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_14:
    // 0x808006EC: beq         $v0, $zero, L_80800708
    if (ctx->r2 == 0) {
        // 0x808006F0: addiu       $t8, $zero, 0x51
        ctx->r24 = ADD32(0, 0X51);
            goto L_80800708;
    }
    // 0x808006F0: addiu       $t8, $zero, 0x51
    ctx->r24 = ADD32(0, 0X51);
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F8: jal         0x800848A0
    // 0x808006FC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _badrone_entrypoint_23(rdram, ctx);
        goto after_15;
    // 0x808006FC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_15:
    // 0x80800700: b           L_8080070C
    // 0x80800704: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
        goto L_8080070C;
    // 0x80800704: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_80800708:
    // 0x80800708: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
L_8080070C:
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800710:
    // 0x80800710: jal         0x80091A58
    // 0x80800714: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_16;
    // 0x80800714: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_16:
    // 0x80800718: beq         $v0, $zero, L_80800728
    if (ctx->r2 == 0) {
        // 0x8080071C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800728;
    }
    // 0x8080071C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800720: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80800724: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_80800728:
    // 0x80800728: lw          $t0, 0x160($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X160);
    // 0x8080072C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800730: bnel        $t0, $zero, L_80800740
    if (ctx->r8 != 0) {
        // 0x80800734: sw          $zero, 0x160($s0)
        MEM_W(0X160, ctx->r16) = 0;
            goto L_80800740;
    }
    goto skip_5;
    // 0x80800734: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    skip_5:
    // 0x80800738: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8080073C: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
L_80800740:
    // 0x80800740: jal         0x8009E5C8
    // 0x80800744: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    bs_setState(rdram, ctx);
        goto after_17;
    // 0x80800744: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_17:
    // 0x80800748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080074C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800750: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800754: jr          $ra
    // 0x80800758: nop

    return;
    // 0x80800758: nop

;}
RECOMP_FUNC void func_8080015C_chgoldsnakehead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800160: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800164: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800168: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080016C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800170: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800174: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800178: beq         $t6, $at, L_808002A0
    if (ctx->r14 == ctx->r1) {
        // 0x8080017C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808002A0;
    }
    // 0x8080017C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800180: beq         $t6, $at, L_8080019C
    if (ctx->r14 == ctx->r1) {
        // 0x80800184: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8080019C;
    }
    // 0x80800184: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80800188: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080018C: beql        $t6, $at, L_808001D8
    if (ctx->r14 == ctx->r1) {
        // 0x80800190: lui         $at, 0xC120
        ctx->r1 = S32(0XC120 << 16);
            goto L_808001D8;
    }
    goto skip_0;
    // 0x80800190: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    skip_0:
    // 0x80800194: b           L_808002A4
    // 0x80800198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002A4;
    // 0x80800198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080019C:
    // 0x8080019C: jal         0x800FC63C
    // 0x808001A0: addiu       $a1, $zero, 0x7FBC
    ctx->r5 = ADD32(0, 0X7FBC);
    func_800FC63C(rdram, ctx);
        goto after_0;
    // 0x808001A0: addiu       $a1, $zero, 0x7FBC
    ctx->r5 = ADD32(0, 0X7FBC);
    after_0:
    // 0x808001A4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808001A8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x808001AC: jal         0x800EE7F8
    // 0x808001B0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808001B0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_1:
    // 0x808001B4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(724, 0X4F0) << 16);
    // 0x808001B8: addiu       $a2, $a2, 0x4F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(724, 0X4F0));
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: jal         0x80089D18
    // 0x808001C4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808001C4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: jal         0x80101FDC
    // 0x808001D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x808001D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808001D4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
L_808001D8:
    // 0x808001D8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001DC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808001E0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001E4: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x808001E8: jal         0x800DC178
    // 0x808001EC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808001EC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_4:
    // 0x808001F0: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x808001F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001F8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x808001FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800200: jal         0x800DC178
    // 0x80800204: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800204: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    after_5:
    // 0x80800208: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: jal         0x80102B2C
    // 0x80800214: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_80102B2C(rdram, ctx);
        goto after_6;
    // 0x80800214: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_6:
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x80102B6C
    // 0x80800220: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_80102B6C(rdram, ctx);
        goto after_7;
    // 0x80800220: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_7:
    // 0x80800224: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800228: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080022C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800230: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800234: jal         0x800DC178
    // 0x80800238: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x80800238: nop

    after_8:
    // 0x8080023C: jal         0x800D8FF8
    // 0x80800240: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_9;
    // 0x80800240: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x80800244: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800248: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080024C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800250: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800254: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800258: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080025C: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x80800260: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800264: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800268: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8080026C: jal         0x800EF214
    // 0x80800270: nop

    func_800EF214(rdram, ctx);
        goto after_10;
    // 0x80800270: nop

    after_10:
    // 0x80800274: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x80800278: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080027C: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800280: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800284: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800288: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8080028C: nop

    // 0x80800290: bc1fl       L_808002A4
    if (!c1cs) {
        // 0x80800294: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002A4;
    }
    goto skip_1;
    // 0x80800294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800298: jal         0x80089CA8
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_808002A0:
    // 0x808002A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002A4:
    // 0x808002A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002AC: jr          $ra
    // 0x808002B0: nop

    return;
    // 0x808002B0: nop

;}
RECOMP_FUNC void func_800B8DEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8DEC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B8DF0: addiu       $v0, $v0, -0x7D40
    ctx->r2 = ADD32(ctx->r2, -0X7D40);
    // 0x800B8DF4: lbu         $t7, 0xC($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XC);
    // 0x800B8DF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B8DFC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800B8E00: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800B8E04: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800B8E08: beq         $t7, $zero, L_800B8E18
    if (ctx->r15 == 0) {
        // 0x800B8E0C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800B8E18;
    }
    // 0x800B8E0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8E10: jal         0x800B81CC
    // 0x800B8E14: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    func_800B81CC(rdram, ctx);
        goto after_0;
    // 0x800B8E14: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    after_0:
L_800B8E18:
    // 0x800B8E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B8E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B8E20: jr          $ra
    // 0x800B8E24: nop

    return;
    // 0x800B8E24: nop

;}
RECOMP_FUNC void func_808041E4_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808041E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808041E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808041EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808041F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808041F4: jal         0x80100094
    // 0x808041F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808041F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808041FC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80804200: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80804204: sltiu       $at, $v1, 0x5
    ctx->r1 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x80804208: beq         $at, $zero, L_808042C4
    if (ctx->r1 == 0) {
        // 0x8080420C: sb          $v1, 0x8($v0)
        MEM_B(0X8, ctx->r2) = ctx->r3;
            goto L_808042C4;
    }
    // 0x8080420C: sb          $v1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r3;
    // 0x80804210: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80804214: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B64) << 16);
    // 0x80804218: addu        $at, $at, $t6
    gpr jr_addend_80804220 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080421C: lw          $t6, -0x649C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B64));
    // 0x80804220: jr          $t6
    // 0x80804224: nop

    switch (jr_addend_80804220 >> 2) {
        case 0: goto L_80804228; break;
        case 1: goto L_80804250; break;
        case 2: goto L_80804260; break;
        case 3: goto L_8080427C; break;
        case 4: goto L_80804298; break;
        default: switch_error(__func__, 0x80804220, 0x80809B64);
    }
    // 0x80804224: nop

L_80804228:
    // 0x80804228: jal         0x80089D48
    // 0x8080422C: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080422C: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    after_1:
    // 0x80804230: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x80804234: jal         0x80089D48
    // 0x80804238: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80804238: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    after_2:
    // 0x8080423C: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x80804240: jal         0x80089D48
    // 0x80804244: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80804244: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    after_3:
    // 0x80804248: b           L_808042C4
    // 0x8080424C: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
        goto L_808042C4;
    // 0x8080424C: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
L_80804250:
    // 0x80804250: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B78) << 16);
    // 0x80804254: lwc1        $f4, -0x6488($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B78));
    // 0x80804258: b           L_808042C4
    // 0x8080425C: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
        goto L_808042C4;
    // 0x8080425C: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
L_80804260:
    // 0x80804260: jal         0x80089D48
    // 0x80804264: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80804264: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    after_4:
    // 0x80804268: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x8080426C: jal         0x80089D48
    // 0x80804270: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80804270: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    after_5:
    // 0x80804274: b           L_808042C4
    // 0x80804278: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
        goto L_808042C4;
    // 0x80804278: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
L_8080427C:
    // 0x8080427C: jal         0x80089D48
    // 0x80804280: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80804280: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    after_6:
    // 0x80804284: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x80804288: jal         0x80089D48
    // 0x8080428C: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x8080428C: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    after_7:
    // 0x80804290: b           L_808042C4
    // 0x80804294: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
        goto L_808042C4;
    // 0x80804294: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
L_80804298:
    // 0x80804298: jal         0x80089D48
    // 0x8080429C: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x8080429C: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    after_8:
    // 0x808042A0: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x808042A4: jal         0x80089D48
    // 0x808042A8: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x808042A8: lbu         $a0, 0xC($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XC);
    after_9:
    // 0x808042AC: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x808042B0: jal         0x80089D48
    // 0x808042B4: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x808042B4: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    after_10:
    // 0x808042B8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808042BC: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x808042C0: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
L_808042C4:
    // 0x808042C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808042C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808042CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808042D0: jr          $ra
    // 0x808042D4: nop

    return;
    // 0x808042D4: nop

;}
RECOMP_FUNC void func_80800BBC_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800BC8: jal         0x808002F8
    // 0x80800BCC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    bssnowball_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800BCC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800BD0: jal         0x80085158
    // 0x80800BD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _baspin_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800BD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800BD8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800BDC: bne         $v0, $at, L_80800BE8
    if (ctx->r2 != ctx->r1) {
        // 0x80800BE0: addiu       $t6, $zero, 0x17D
        ctx->r14 = ADD32(0, 0X17D);
            goto L_80800BE8;
    }
    // 0x80800BE0: addiu       $t6, $zero, 0x17D
    ctx->r14 = ADD32(0, 0X17D);
    // 0x80800BE4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800BE8:
    // 0x80800BE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800BEC: jal         0x8009E5C8
    // 0x80800BF0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800BF0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800BFC: jr          $ra
    // 0x80800C00: nop

    return;
    // 0x80800C00: nop

;}
RECOMP_FUNC void func_80800000_chfantasysafe(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: lui         $a1, 0x458D
    ctx->r5 = S32(0X458D << 16);
    // 0x80800014: lui         $a2, 0xC43B
    ctx->r6 = S32(0XC43B << 16);
    // 0x80800018: lui         $a3, 0x450E
    ctx->r7 = S32(0X450E << 16);
    // 0x8080001C: ori         $a3, $a3, 0x599A
    ctx->r7 = ctx->r7 | 0X599A;
    // 0x80800020: ori         $a2, $a2, 0x2666
    ctx->r6 = ctx->r6 | 0X2666;
    // 0x80800024: ori         $a1, $a1, 0xDB33
    ctx->r5 = ctx->r5 | 0XDB33;
    // 0x80800028: jal         0x800EFA4C
    // 0x8080002C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x8080002C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800030: jal         0x80088848
    // 0x80800034: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800034: nop

    after_1:
    // 0x80800038: beq         $v0, $zero, L_80800084
    if (ctx->r2 == 0) {
        // 0x8080003C: lui         $at, 0x4364
        ctx->r1 = S32(0X4364 << 16);
            goto L_80800084;
    }
    // 0x8080003C: lui         $at, 0x4364
    ctx->r1 = S32(0X4364 << 16);
    // 0x80800040: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800044: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    // 0x80800048: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080004C: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80800050: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x80800054: sb          $t7, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r15;
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080005C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800060: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x80800064: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x80800068: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
    // 0x8080006C: swc1        $f2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f2.u32l;
    // 0x80800070: swc1        $f2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f2.u32l;
    // 0x80800074: jal         0x80101FDC
    // 0x80800078: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800078: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8080007C: b           L_80800190
    // 0x80800080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800190;
    // 0x80800080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800084:
    // 0x80800084: jal         0x800DA298
    // 0x80800088: addiu       $a0, $zero, 0x38D
    ctx->r4 = ADD32(0, 0X38D);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800088: addiu       $a0, $zero, 0x38D
    ctx->r4 = ADD32(0, 0X38D);
    after_3:
    // 0x8080008C: beq         $v0, $zero, L_808000C4
    if (ctx->r2 == 0) {
        // 0x80800090: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_808000C4;
    }
    // 0x80800090: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800094: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800098: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8080009C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808000A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808000AC: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x808000B0: swc1        $f2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f2.u32l;
    // 0x808000B4: jal         0x80101FDC
    // 0x808000B8: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808000B8: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x808000BC: b           L_80800190
    // 0x808000C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800190;
    // 0x808000C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000C4:
    // 0x808000C4: jal         0x800DA298
    // 0x808000C8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x808000C8: addiu       $a0, $zero, 0x38B
    ctx->r4 = ADD32(0, 0X38B);
    after_5:
    // 0x808000CC: beq         $v0, $zero, L_808000DC
    if (ctx->r2 == 0) {
        // 0x808000D0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_808000DC;
    }
    // 0x808000D0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808000D4: b           L_808000E0
    // 0x808000D8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
        goto L_808000E0;
    // 0x808000D8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_808000DC:
    // 0x808000DC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_808000E0:
    // 0x808000E0: jal         0x800DA298
    // 0x808000E4: addiu       $a0, $zero, 0x38A
    ctx->r4 = ADD32(0, 0X38A);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808000E4: addiu       $a0, $zero, 0x38A
    ctx->r4 = ADD32(0, 0X38A);
    after_6:
    // 0x808000E8: beq         $v0, $zero, L_808000F8
    if (ctx->r2 == 0) {
        // 0x808000EC: addiu       $a0, $zero, 0x389
        ctx->r4 = ADD32(0, 0X389);
            goto L_808000F8;
    }
    // 0x808000EC: addiu       $a0, $zero, 0x389
    ctx->r4 = ADD32(0, 0X389);
    // 0x808000F0: b           L_808000FC
    // 0x808000F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_808000FC;
    // 0x808000F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808000F8:
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_808000FC:
    // 0x808000FC: jal         0x800DA298
    // 0x80800100: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800100: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_7:
    // 0x80800104: beq         $v0, $zero, L_80800114
    if (ctx->r2 == 0) {
        // 0x80800108: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80800114;
    }
    // 0x80800108: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080010C: b           L_80800118
    // 0x80800110: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800118;
    // 0x80800110: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800114:
    // 0x80800114: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800118:
    // 0x80800118: addiu       $a0, $zero, 0x38C
    ctx->r4 = ADD32(0, 0X38C);
    // 0x8080011C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80800120: jal         0x800DA298
    // 0x80800124: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800124: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_8:
    // 0x80800128: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8080012C: beq         $v0, $zero, L_8080013C
    if (ctx->r2 == 0) {
        // 0x80800130: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_8080013C;
    }
    // 0x80800130: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800134: b           L_80800140
    // 0x80800138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800140;
    // 0x80800138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080013C:
    // 0x8080013C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800140:
    // 0x80800140: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80800144: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80800148: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x8080014C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80800150: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x80800154: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80800158: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8080015C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80800160: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2380, 0X998) << 16);
    // 0x80800164: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800168: lwc1        $f0, 0x998($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2380, 0X998));
    // 0x8080016C: lui         $at, 0x4364
    ctx->r1 = S32(0X4364 << 16);
    // 0x80800170: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800174: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800178: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8080017C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800180: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80800184: swc1        $f2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f2.u32l;
    // 0x80800188: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x8080018C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800190:
    // 0x80800190: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800194: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800198: jr          $ra
    // 0x8080019C: nop

    return;
    // 0x8080019C: nop

;}
RECOMP_FUNC void func_800C9BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9BB4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800C9BB8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C9BBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C9BC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C9BC4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C9BC8: mul.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x800C9BCC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C9BD0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800C9BD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C9BD8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800C9BDC: addiu       $a1, $a1, -0x664C
    ctx->r5 = ADD32(ctx->r5, -0X664C);
    // 0x800C9BE0: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x800C9BE4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800C9BE8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800C9BEC: jal         0x800C9E64
    // 0x800C9BF0: nop

    func_800C9E64(rdram, ctx);
        goto after_0;
    // 0x800C9BF0: nop

    after_0:
    // 0x800C9BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9BF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C9BFC: jr          $ra
    // 0x800C9C00: nop

    return;
    // 0x800C9C00: nop

;}
RECOMP_FUNC void func_80802118_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080211C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802120: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802124: lbu         $a1, 0x5F($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X5F);
    // 0x80802128: beql        $a1, $zero, L_80802154
    if (ctx->r5 == 0) {
        // 0x8080212C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802154;
    }
    goto skip_0;
    // 0x8080212C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802130: jal         0x800C3D78
    // 0x80802134: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    func_800C3D78(rdram, ctx);
        goto after_0;
    // 0x80802134: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    after_0:
    // 0x80802138: bne         $v0, $zero, L_80802150
    if (ctx->r2 != 0) {
        // 0x8080213C: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_80802150;
    }
    // 0x8080213C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80802140: jal         0x800C2FDC
    // 0x80802144: lbu         $a0, 0x5F($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X5F);
    func_800C2FDC(rdram, ctx);
        goto after_1;
    // 0x80802144: lbu         $a0, 0x5F($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X5F);
    after_1:
    // 0x80802148: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8080214C: sb          $zero, 0x5F($t8)
    MEM_B(0X5F, ctx->r24) = 0;
L_80802150:
    // 0x80802150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802154:
    // 0x80802154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802158: jr          $ra
    // 0x8080215C: nop

    return;
    // 0x8080215C: nop

;}
RECOMP_FUNC void _chcauldronentrydoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800870B0: syscall     509
    recomp_syscall_handler(rdram, ctx, 0x800870B0);
    return;
    // 0x800870B4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808003C4_chfactoryroofbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003D4: lw          $a0, 0x6C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6C);
    // 0x808003D8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808003DC: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x808003E0: srl         $t6, $a0, 21
    ctx->r14 = S32(U32(ctx->r4) >> 21);
    // 0x808003E4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x808003E8: jal         0x808001C0
    // 0x808003EC: addiu       $a3, $s0, 0x44
    ctx->r7 = ADD32(ctx->r16, 0X44);
    func_808001C0_chfactoryroofbits(rdram, ctx);
        goto after_0;
    // 0x808003EC: addiu       $a3, $s0, 0x44
    ctx->r7 = ADD32(ctx->r16, 0X44);
    after_0:
    // 0x808003F0: beql        $v0, $zero, L_80800404
    if (ctx->r2 == 0) {
        // 0x808003F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800404;
    }
    goto skip_0;
    // 0x808003F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808003F8: jal         0x800FFA88
    // 0x808003FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_1;
    // 0x808003FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x80800400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800404:
    // 0x80800404: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800408: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080040C: jr          $ra
    // 0x80800410: nop

    return;
    // 0x80800410: nop

;}
RECOMP_FUNC void bsbansnooze_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800638: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080063C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(49, 0XA78) << 16);
    // 0x80800640: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800644: jr          $ra
    // 0x80800648: lw          $v0, 0xA78($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(49, 0XA78));
    return;
    // 0x80800648: lw          $v0, 0xA78($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(49, 0XA78));
;}
RECOMP_FUNC void func_8080101C_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080101C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801024: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801028: jal         0x80100094
    // 0x8080102C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080102C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801030: addiu       $a0, $v0, 0x28
    ctx->r4 = ADD32(ctx->r2, 0X28);
    // 0x80801034: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80801038: jal         0x800899C8
    // 0x8080103C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x8080103C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80801040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801048: jr          $ra
    // 0x8080104C: nop

    return;
    // 0x8080104C: nop

;}
RECOMP_FUNC void func_808004BC_chconga(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808004C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808004CC: jal         0x800C6E38
    // 0x808004D0: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x808004D0: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_0:
    // 0x808004D4: beq         $v0, $zero, L_808004F4
    if (ctx->r2 == 0) {
        // 0x808004D8: nop
    
            goto L_808004F4;
    }
    // 0x808004D8: nop

    // 0x808004DC: jal         0x800C6E38
    // 0x808004E0: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    func_800C6E38(rdram, ctx);
        goto after_1;
    // 0x808004E0: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_1:
    // 0x808004E4: beq         $v0, $zero, L_808004F4
    if (ctx->r2 == 0) {
        // 0x808004E8: nop
    
            goto L_808004F4;
    }
    // 0x808004E8: nop

    // 0x808004EC: b           L_80800524
    // 0x808004F0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_80800524;
    // 0x808004F0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_808004F4:
    // 0x808004F4: jal         0x800C6E38
    // 0x808004F8: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    func_800C6E38(rdram, ctx);
        goto after_2;
    // 0x808004F8: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_2:
    // 0x808004FC: beq         $v0, $zero, L_8080050C
    if (ctx->r2 == 0) {
        // 0x80800500: nop
    
            goto L_8080050C;
    }
    // 0x80800500: nop

    // 0x80800504: b           L_80800524
    // 0x80800508: addiu       $v1, $zero, 0x1112
    ctx->r3 = ADD32(0, 0X1112);
        goto L_80800524;
    // 0x80800508: addiu       $v1, $zero, 0x1112
    ctx->r3 = ADD32(0, 0X1112);
L_8080050C:
    // 0x8080050C: jal         0x800C6E38
    // 0x80800510: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    func_800C6E38(rdram, ctx);
        goto after_3;
    // 0x80800510: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_3:
    // 0x80800514: beq         $v0, $zero, L_80800524
    if (ctx->r2 == 0) {
        // 0x80800518: addiu       $v1, $zero, 0x1113
        ctx->r3 = ADD32(0, 0X1113);
            goto L_80800524;
    }
    // 0x80800518: addiu       $v1, $zero, 0x1113
    ctx->r3 = ADD32(0, 0X1113);
    // 0x8080051C: b           L_80800524
    // 0x80800520: addiu       $v1, $zero, 0x10FF
    ctx->r3 = ADD32(0, 0X10FF);
        goto L_80800524;
    // 0x80800520: addiu       $v1, $zero, 0x10FF
    ctx->r3 = ADD32(0, 0X10FF);
L_80800524:
    // 0x80800524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080052C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800530: jr          $ra
    // 0x80800534: nop

    return;
    // 0x80800534: nop

;}
RECOMP_FUNC void _ncpoddialog_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895D8: syscall     784
    recomp_syscall_handler(rdram, ctx, 0x800895D8);
    return;
    // 0x800895DC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bamovespline_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E78: syscall     140
    recomp_syscall_handler(rdram, ctx, 0x80084E78);
    return;
    // 0x80084E7C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800CC0_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CC8: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800CCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800CD0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800CD4: beq         $t6, $zero, L_80800CEC
    if (ctx->r14 == 0) {
        // 0x80800CD8: nop
    
            goto L_80800CEC;
    }
    // 0x80800CD8: nop

    // 0x80800CDC: beq         $t6, $at, L_80800CEC
    if (ctx->r14 == ctx->r1) {
        // 0x80800CE0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800CEC;
    }
    // 0x80800CE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800CE4: bne         $t6, $at, L_80800CFC
    if (ctx->r14 != ctx->r1) {
        // 0x80800CE8: nop
    
            goto L_80800CFC;
    }
    // 0x80800CE8: nop

L_80800CEC:
    // 0x80800CEC: jal         0x8008A4B0
    // 0x80800CF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800CF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800CF4: b           L_80800D08
    // 0x80800CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800D08;
    // 0x80800CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CFC:
    // 0x80800CFC: jal         0x8008A4B0
    // 0x80800D00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800D00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D08:
    // 0x80800D08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D0C: jr          $ra
    // 0x80800D10: nop

    return;
    // 0x80800D10: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_49(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802F4C: lbu         $t9, 0x1D($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1D);
    // 0x80802F50: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80802F54: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80802F58: andi        $t0, $t9, 0xFFFD
    ctx->r8 = ctx->r25 & 0XFFFD;
    // 0x80802F5C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80802F60: jr          $ra
    // 0x80802F64: sb          $t1, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r9;
    return;
    // 0x80802F64: sb          $t1, 0x1D($a0)
    MEM_B(0X1D, ctx->r4) = ctx->r9;
    // 0x80802F68: nop

    // 0x80802F6C: nop

;}
RECOMP_FUNC void func_80800040_chrainripples(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80800044: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8080004C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800050: sw          $s7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r23;
    // 0x80800054: sw          $s6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r22;
    // 0x80800058: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x8080005C: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x80800060: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x80800064: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80800068: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x8080006C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800070: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800074: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800078: jal         0x800B7C98
    // 0x8080007C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800B7C98(rdram, ctx);
        goto after_0;
    // 0x8080007C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x80800080: beq         $v0, $zero, L_808001C0
    if (ctx->r2 == 0) {
        // 0x80800084: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808001C0;
    }
    // 0x80800084: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800088: jal         0x800888F8
    // 0x8080008C: nop

    _fxrain_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080008C: nop

    after_1:
    // 0x80800090: beql        $v0, $zero, L_808001C4
    if (ctx->r2 == 0) {
        // 0x80800094: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_808001C4;
    }
    goto skip_0;
    // 0x80800094: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x80800098: jal         0x800D8FF8
    // 0x8080009C: nop

    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x8080009C: nop

    after_2:
    // 0x808000A0: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x808000A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808000A8: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808000AC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808000B0: bgez        $t7, L_808000C4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808000B4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808000C4;
    }
    // 0x808000B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000BC: nop

    // 0x808000C0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808000C4:
    // 0x808000C4: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808000C8: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x808000CC: srl         $t9, $a0, 25
    ctx->r25 = S32(U32(ctx->r4) >> 25);
    // 0x808000D0: addiu       $a0, $t9, -0x1
    ctx->r4 = ADD32(ctx->r25, -0X1);
    // 0x808000D4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808000D8: mfc1        $s6, $f16
    ctx->r22 = (int32_t)ctx->f16.u32l;
    // 0x808000DC: jal         0x800CC5F4
    // 0x808000E0: nop

    func_800CC5F4(rdram, ctx);
        goto after_3;
    // 0x808000E0: nop

    after_3:
    // 0x808000E4: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x808000E8: beq         $s6, $zero, L_808000FC
    if (ctx->r22 == 0) {
        // 0x808000EC: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_808000FC;
    }
    // 0x808000EC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x808000F0: jal         0x800B5BE4
    // 0x808000F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800B5BE4(rdram, ctx);
        goto after_4;
    // 0x808000F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x808000F8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_808000FC:
    // 0x808000FC: blez        $s6, L_808001C0
    if (SIGNED(ctx->r22) <= 0) {
        // 0x80800100: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_808001C0;
    }
    // 0x80800100: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800104: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800108: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8080010C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1196, 0X280) << 16);
    // 0x80800110: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(1196, 0X2D8) << 16);
    // 0x80800114: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800118: addiu       $s4, $s4, 0x2D8
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(1196, 0X2D8));
    // 0x8080011C: lwc1        $f24, 0x280($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1196, 0X280));
    // 0x80800120: addiu       $s2, $sp, 0x6C
    ctx->r18 = ADD32(ctx->r29, 0X6C);
    // 0x80800124: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
L_80800128:
    // 0x80800128: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x8080012C: srl         $t0, $a0, 25
    ctx->r8 = S32(U32(ctx->r4) >> 25);
    // 0x80800130: jal         0x800CC63C
    // 0x80800134: addiu       $a0, $t0, -0x1
    ctx->r4 = ADD32(ctx->r8, -0X1);
    func_800CC63C(rdram, ctx);
        goto after_5;
    // 0x80800134: addiu       $a0, $t0, -0x1
    ctx->r4 = ADD32(ctx->r8, -0X1);
    after_5:
    // 0x80800138: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080013C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800140: jal         0x800EE7F8
    // 0x80800144: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800144: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80800148: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x8080014C: jal         0x800DC178
    // 0x80800150: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80800150: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_7:
    // 0x80800154: lh          $t1, 0xC($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XC);
    // 0x80800158: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8080015C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800160: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80800164: jal         0x800DC178
    // 0x80800168: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x80800168: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_8:
    // 0x8080016C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800170: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800174: jal         0x800EF1B8
    // 0x80800178: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EF1B8(rdram, ctx);
        goto after_9;
    // 0x80800178: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x8080017C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800180: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80800184: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80800188: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080018C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800190: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800194: jal         0x800BABB8
    // 0x80800198: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    func_800BABB8(rdram, ctx);
        goto after_10;
    // 0x80800198: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x8080019C: lw          $t2, 0x28($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X28);
    // 0x808001A0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x808001A4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x808001A8: slt         $at, $t3, $s7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x808001AC: bne         $at, $zero, L_808001B8
    if (ctx->r1 != 0) {
        // 0x808001B0: sw          $t3, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r11;
            goto L_808001B8;
    }
    // 0x808001B0: sw          $t3, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r11;
    // 0x808001B4: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
L_808001B8:
    // 0x808001B8: bnel        $s3, $s6, L_80800128
    if (ctx->r19 != ctx->r22) {
        // 0x808001BC: lw          $a0, 0x70($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X70);
            goto L_80800128;
    }
    goto skip_1;
    // 0x808001BC: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    skip_1:
L_808001C0:
    // 0x808001C0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_808001C4:
    // 0x808001C4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808001C8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808001CC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808001D0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808001D4: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x808001D8: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x808001DC: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x808001E0: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x808001E4: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x808001E8: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x808001EC: lw          $s6, 0x54($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X54);
    // 0x808001F0: lw          $s7, 0x58($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X58);
    // 0x808001F4: jr          $ra
    // 0x808001F8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x808001F8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800A5930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5938: jal         0x800EA05C
    // 0x800A593C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x800A593C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A5940: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5944: lw          $t0, 0x70F0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X70F0);
    // 0x800A5948: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800A594C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A5950: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x800A5954: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A5958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A595C: beq         $t6, $zero, L_800A5998
    if (ctx->r14 == 0) {
        // 0x800A5960: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_800A5998;
    }
    // 0x800A5960: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x800A5964: lh          $a0, 0x0($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X0);
L_800A5968:
    // 0x800A5968: bnel        $v0, $a0, L_800A5988
    if (ctx->r2 != ctx->r4) {
        // 0x800A596C: lh          $a0, 0x16($v1)
        ctx->r4 = MEM_H(ctx->r3, 0X16);
            goto L_800A5988;
    }
    goto skip_0;
    // 0x800A596C: lh          $a0, 0x16($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X16);
    skip_0:
    // 0x800A5970: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    // 0x800A5974: bnel        $a3, $t7, L_800A5988
    if (ctx->r7 != ctx->r15) {
        // 0x800A5978: lh          $a0, 0x16($v1)
        ctx->r4 = MEM_H(ctx->r3, 0X16);
            goto L_800A5988;
    }
    goto skip_1;
    // 0x800A5978: lh          $a0, 0x16($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X16);
    skip_1:
    // 0x800A597C: b           L_800A59B0
    // 0x800A5980: addu        $v0, $a1, $t0
    ctx->r2 = ADD32(ctx->r5, ctx->r8);
        goto L_800A59B0;
    // 0x800A5980: addu        $v0, $a1, $t0
    ctx->r2 = ADD32(ctx->r5, ctx->r8);
    // 0x800A5984: lh          $a0, 0x16($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X16);
L_800A5988:
    // 0x800A5988: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800A598C: addiu       $a1, $a1, 0x16
    ctx->r5 = ADD32(ctx->r5, 0X16);
    // 0x800A5990: bne         $a0, $zero, L_800A5968
    if (ctx->r4 != 0) {
        // 0x800A5994: addiu       $v1, $v1, 0x16
        ctx->r3 = ADD32(ctx->r3, 0X16);
            goto L_800A5968;
    }
    // 0x800A5994: addiu       $v1, $v1, 0x16
    ctx->r3 = ADD32(ctx->r3, 0X16);
L_800A5998:
    // 0x800A5998: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800A599C: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x800A59A0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800A59A4: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x800A59A8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800A59AC: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
L_800A59B0:
    // 0x800A59B0: jr          $ra
    // 0x800A59B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800A59B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800114_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800114: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800118: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080011C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800120: jal         0x80083808
    // 0x80800124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsmum_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800124: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: jal         0x8009E6C4
    // 0x80800130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E6C4(rdram, ctx);
        goto after_1;
    // 0x80800130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800134: bne         $v0, $zero, L_80800184
    if (ctx->r2 != 0) {
        // 0x80800138: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800184;
    }
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: jal         0x8009BCB4
    // 0x80800140: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_2;
    // 0x80800140: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_2:
    // 0x80800144: lui         $a1, 0x4305
    ctx->r5 = S32(0X4305 << 16);
    // 0x80800148: ori         $a1, $a1, 0x547B
    ctx->r5 = ctx->r5 | 0X547B;
    // 0x8080014C: jal         0x8009BCC4
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800154: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x80800158: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: jal         0x8009F1C8
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_4;
    // 0x80800164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800170: jal         0x8009F1C8
    // 0x80800174: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_5;
    // 0x80800174: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080017C: jal         0x800961AC
    // 0x80800180: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800961AC(rdram, ctx);
        goto after_6;
    // 0x80800180: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
L_80800184:
    // 0x80800184: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800188: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080018C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800190: jr          $ra
    // 0x80800194: nop

    return;
    // 0x80800194: nop

;}
RECOMP_FUNC void func_808004E0_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808004E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004E8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808004EC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808004F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808004F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808004F8: jal         0x80100094
    // 0x808004FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808004FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800500: addiu       $t6, $v0, 0x14
    ctx->r14 = ADD32(ctx->r2, 0X14);
    // 0x80800504: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80800508: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8080050C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800510: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800514: blez        $t7, L_80800564
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80800518: nop
    
            goto L_80800564;
    }
    // 0x80800518: nop

L_8080051C:
    // 0x8080051C: jal         0x800F53D0
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F53D0(rdram, ctx);
        goto after_1;
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800524: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800528: jal         0x80088378
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcstatusDll_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800530: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800534: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800538: jal         0x800842A8
    // 0x8080053C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bsfirstp_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x8080053C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800540: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800544: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800548: jal         0x800842B0
    // 0x8080054C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    _bsfirstp_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x8080054C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_4:
    // 0x80800550: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80800554: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800558: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8080055C: bne         $at, $zero, L_8080051C
    if (ctx->r1 != 0) {
        // 0x80800560: nop
    
            goto L_8080051C;
    }
    // 0x80800560: nop

L_80800564:
    // 0x80800564: jal         0x80089980
    // 0x80800568: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _sumultiscore_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800568: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x8080056C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800570: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800574: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800578: jal         0x80089988
    // 0x8080057C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x8080057C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80800580: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800584: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800588: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8080058C: jal         0x80089988
    // 0x80800590: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800590: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80800594: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800598: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080059C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808005A0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808005A4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808005A8: jr          $ra
    // 0x808005AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808005AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void subaddierouteDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800080: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800084: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800088: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080008C: jal         0x801015B0
    // 0x80800090: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_801015B0(rdram, ctx);
        goto after_0;
    // 0x80800090: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800094: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80800098: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080009C: beql        $t6, $zero, L_80800104
    if (ctx->r14 == 0) {
        // 0x808000A0: sh          $zero, 0x2($s2)
        MEM_H(0X2, ctx->r18) = 0;
            goto L_80800104;
    }
    goto skip_0;
    // 0x808000A0: sh          $zero, 0x2($s2)
    MEM_H(0X2, ctx->r18) = 0;
    skip_0:
    // 0x808000A4: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x808000A8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808000AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808000B0: blez        $t7, L_808000F4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x808000B4: nop
    
            goto L_808000F4;
    }
    // 0x808000B4: nop

L_808000B8:
    // 0x808000B8: jal         0x8001B798
    // 0x808000BC: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x808000BC: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    after_1:
    // 0x808000C0: addu        $t8, $v0, $s0
    ctx->r24 = ADD32(ctx->r2, ctx->r16);
    // 0x808000C4: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x808000C8: addu        $t0, $v0, $s0
    ctx->r8 = ADD32(ctx->r2, ctx->r16);
    // 0x808000CC: beql        $t9, $zero, L_808000E0
    if (ctx->r25 == 0) {
        // 0x808000D0: lh          $t1, 0x2($s2)
        ctx->r9 = MEM_H(ctx->r18, 0X2);
            goto L_808000E0;
    }
    goto skip_1;
    // 0x808000D0: lh          $t1, 0x2($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X2);
    skip_1:
    // 0x808000D4: jal         0x8001B754
    // 0x808000D8: lh          $a0, 0x0($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X0);
    func_8001B754(rdram, ctx);
        goto after_2;
    // 0x808000D8: lh          $a0, 0x0($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X0);
    after_2:
    // 0x808000DC: lh          $t1, 0x2($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X2);
L_808000E0:
    // 0x808000E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808000E4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808000E8: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x808000EC: bne         $at, $zero, L_808000B8
    if (ctx->r1 != 0) {
        // 0x808000F0: nop
    
            goto L_808000B8;
    }
    // 0x808000F0: nop

L_808000F4:
    // 0x808000F4: jal         0x8001B754
    // 0x808000F8: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    func_8001B754(rdram, ctx);
        goto after_3;
    // 0x808000F8: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    after_3:
    // 0x808000FC: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    // 0x80800100: sh          $zero, 0x2($s2)
    MEM_H(0X2, ctx->r18) = 0;
L_80800104:
    // 0x80800104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800108: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080010C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800110: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800114: jr          $ra
    // 0x80800118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chanim_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800859A8: syscall     184
    recomp_syscall_handler(rdram, ctx, 0x800859A8);
    return;
    // 0x800859AC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void bskazspring_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800404: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800408: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(284, 0X430) << 16);
    // 0x8080040C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800410: jr          $ra
    // 0x80800414: lw          $v0, 0x430($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(284, 0X430));
    return;
    // 0x80800414: lw          $v0, 0x430($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(284, 0X430));
;}
RECOMP_FUNC void func_80800400_chpowerhut(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800400: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800408: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080040C: jal         0x80086C68
    // 0x80800410: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _chmumbopad_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800410: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80800414: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x80800418: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8080041C: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80800420: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800428: jal         0x80089840
    // 0x8080042C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    _sumumbofx_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x8080042C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_1:
    // 0x80800430: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800434: jal         0x80100094
    // 0x80800438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8080043C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800440: jal         0x80089850
    // 0x80800444: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800444: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800448: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080044C: jal         0x80089900
    // 0x80800450: lui         $a1, 0x4010
    ctx->r5 = S32(0X4010 << 16);
    _sumumbofx_entrypoint_24(rdram, ctx);
        goto after_4;
    // 0x80800450: lui         $a1, 0x4010
    ctx->r5 = S32(0X4010 << 16);
    after_4:
    // 0x80800454: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800458: jal         0x800898B8
    // 0x8080045C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_15(rdram, ctx);
        goto after_5;
    // 0x8080045C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_5:
    // 0x80800460: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800464: jal         0x800898E0
    // 0x80800468: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _sumumbofx_entrypoint_20(rdram, ctx);
        goto after_6;
    // 0x80800468: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_6:
    // 0x8080046C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800470: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800474: jr          $ra
    // 0x80800478: nop

    return;
    // 0x80800478: nop

;}
RECOMP_FUNC void bsbbarge_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808001D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001D8: jal         0x8008CABC
    // 0x808001DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808001DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808001E0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808001E4: jal         0x8008AF24
    // 0x808001E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x808001E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808001EC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808001F0: jal         0x8008B1A0
    // 0x808001F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x808001F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808001F8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808001FC: jal         0x8008AED4
    // 0x80800200: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800200: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_3:
    // 0x80800204: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800208: jal         0x8008B1BC
    // 0x8080020C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x8080020C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x80800210: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800214: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800218: jal         0x8008B1D4
    // 0x8080021C: lui         $a2, 0x3EC0
    ctx->r6 = S32(0X3EC0 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_5;
    // 0x8080021C: lui         $a2, 0x3EC0
    ctx->r6 = S32(0X3EC0 << 16);
    after_5:
    // 0x80800220: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800224: jal         0x8008B134
    // 0x80800228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x80800228: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080022C: jal         0x8008B064
    // 0x80800230: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x80800230: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80800234: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x80800238: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800240: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800244: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800248: jal         0x8009FFD8
    // 0x8080024C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_8;
    // 0x8080024C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_8:
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80800258: jal         0x8009C99C
    // 0x8080025C: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_9;
    // 0x8080025C: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_9:
    // 0x80800260: jal         0x8009C990
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_10;
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800268: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080026C: jal         0x8009B9C0
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_11;
    // 0x80800270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800274: jal         0x8009BB00
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080027C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(57, 0X618) << 16);
    // 0x80800280: lwc1        $f4, 0x618($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(57, 0X618));
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800288: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080028C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800290: jal         0x8009B9B0
    // 0x80800294: nop

    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_13;
    // 0x80800294: nop

    after_13:
    // 0x80800298: jal         0x8009C990
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_14;
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808002A0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808002A4: jal         0x8009BB00
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_15;
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808002AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B4: jal         0x8009BA68
    // 0x808002B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_16;
    // 0x808002B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_16:
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C0: jal         0x800A0CF4
    // 0x808002C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_17;
    // 0x808002C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002CC: jal         0x80095774
    // 0x808002D0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    baflag_clear(rdram, ctx);
        goto after_18;
    // 0x808002D0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_18:
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D8: jal         0x80095774
    // 0x808002DC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    baflag_clear(rdram, ctx);
        goto after_19;
    // 0x808002DC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_19:
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E4: jal         0x80095774
    // 0x808002E8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    baflag_clear(rdram, ctx);
        goto after_20;
    // 0x808002E8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_20:
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F0: jal         0x80095774
    // 0x808002F4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    baflag_clear(rdram, ctx);
        goto after_21;
    // 0x808002F4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_21:
    // 0x808002F8: jal         0x8009E4AC
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_22;
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800308: jal         0x8009E5A4
    // 0x8080030C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8009E5A4(rdram, ctx);
        goto after_23;
    // 0x8080030C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_23:
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800314: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800318: jal         0x8009E55C
    // 0x8080031C: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_8009E55C(rdram, ctx);
        goto after_24;
    // 0x8080031C: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_24:
    // 0x80800320: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800328: jal         0x80800000
    // 0x8080032C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bsbbarge_setSubstate(rdram, ctx);
        goto after_25;
    // 0x8080032C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x80800330: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800334: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800338: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080033C: jr          $ra
    // 0x80800340: nop

    return;
    // 0x80800340: nop

;}
RECOMP_FUNC void bakey_released(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091A30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80091A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80091A38: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80091A3C: jal         0x800BCE84
    // 0x80091A40: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800BCE84(rdram, ctx);
        goto after_0;
    // 0x80091A40: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x80091A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80091A48: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80091A4C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80091A50: jr          $ra
    // 0x80091A54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80091A54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808011BC_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011BC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808011C0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808011C4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808011C8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808011CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808011D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808011D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808011D8: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x808011DC: jal         0x80100094
    // 0x808011E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808011E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808011E4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808011E8: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x808011EC: jal         0x80088368
    // 0x808011F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808011F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_1:
    // 0x808011F4: blez        $v0, L_80801250
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808011F8: addiu       $s2, $s4, 0x28
        ctx->r18 = ADD32(ctx->r20, 0X28);
            goto L_80801250;
    }
    // 0x808011F8: addiu       $s2, $s4, 0x28
    ctx->r18 = ADD32(ctx->r20, 0X28);
    // 0x808011FC: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80801200: addiu       $t7, $sp, 0x5C
    ctx->r15 = ADD32(ctx->r29, 0X5C);
    // 0x80801204: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80801208: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8080120C:
    // 0x8080120C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801210: jal         0x800899A8
    // 0x80801214: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _sumultiscore_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80801214: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x80801218: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080121C: beq         $at, $zero, L_80801228
    if (ctx->r1 == 0) {
        // 0x80801220: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80801228;
    }
    // 0x80801220: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80801224: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_80801228:
    // 0x80801228: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080122C: jal         0x800AA20C
    // 0x80801230: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800AA20C(rdram, ctx);
        goto after_3;
    // 0x80801230: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80801234: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801238: jal         0x80088368
    // 0x8080123C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x8080123C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80801240: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801244: bnel        $at, $zero, L_8080120C
    if (ctx->r1 != 0) {
        // 0x80801248: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080120C;
    }
    goto skip_0;
    // 0x80801248: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x8080124C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80801250:
    // 0x80801250: jal         0x80088368
    // 0x80801254: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80801254: nop

    after_5:
    // 0x80801258: blez        $v0, L_8080129C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080125C: sll         $t8, $s1, 2
        ctx->r24 = S32(ctx->r17 << 2);
            goto L_8080129C;
    }
    // 0x8080125C: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80801260: addiu       $t9, $sp, 0x5C
    ctx->r25 = ADD32(ctx->r29, 0X5C);
    // 0x80801264: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x80801268: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
L_8080126C:
    // 0x8080126C: addiu       $a0, $s4, 0x28
    ctx->r4 = ADD32(ctx->r20, 0X28);
    // 0x80801270: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801274: bne         $s3, $t0, L_80801284
    if (ctx->r19 != ctx->r8) {
        // 0x80801278: addiu       $a2, $zero, 0x8
        ctx->r6 = ADD32(0, 0X8);
            goto L_80801284;
    }
    // 0x80801278: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8080127C: jal         0x800899C0
    // 0x80801280: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    _sumultiscore_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80801280: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_6:
L_80801284:
    // 0x80801284: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801288: jal         0x80088368
    // 0x8080128C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x8080128C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80801290: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801294: bnel        $at, $zero, L_8080126C
    if (ctx->r1 != 0) {
        // 0x80801298: lw          $t0, 0x0($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X0);
            goto L_8080126C;
    }
    goto skip_1;
    // 0x80801298: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    skip_1:
L_8080129C:
    // 0x8080129C: jal         0x80088368
    // 0x808012A0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x808012A0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    after_8:
    // 0x808012A4: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x808012A8: bne         $at, $zero, L_80801324
    if (ctx->r1 != 0) {
        // 0x808012AC: addiu       $s2, $sp, 0x5C
        ctx->r18 = ADD32(ctx->r29, 0X5C);
            goto L_80801324;
    }
    // 0x808012AC: addiu       $s2, $sp, 0x5C
    ctx->r18 = ADD32(ctx->r29, 0X5C);
    // 0x808012B0: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
L_808012B4:
    // 0x808012B4: blez        $s0, L_80801310
    if (SIGNED(ctx->r16) <= 0) {
        // 0x808012B8: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80801310;
    }
    // 0x808012B8: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x808012BC: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x808012C0: addu        $v0, $s2, $t1
    ctx->r2 = ADD32(ctx->r18, ctx->r9);
    // 0x808012C4: lw          $t2, -0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X4);
    // 0x808012C8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x808012CC: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x808012D0: addu        $v0, $s2, $t4
    ctx->r2 = ADD32(ctx->r18, ctx->r12);
    // 0x808012D4: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x808012D8: beq         $at, $zero, L_80801310
    if (ctx->r1 == 0) {
        // 0x808012DC: nop
    
            goto L_80801310;
    }
    // 0x808012DC: nop

    // 0x808012E0: lw          $a0, -0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X4);
    // 0x808012E4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808012E8: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_808012EC:
    // 0x808012EC: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x808012F0: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x808012F4: bne         $at, $zero, L_80801310
    if (ctx->r1 != 0) {
        // 0x808012F8: sw          $a1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r5;
            goto L_80801310;
    }
    // 0x808012F8: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x808012FC: lw          $a0, -0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X4);
    // 0x80801300: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80801304: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80801308: bnel        $at, $zero, L_808012EC
    if (ctx->r1 != 0) {
        // 0x8080130C: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_808012EC;
    }
    goto skip_2;
    // 0x8080130C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    skip_2:
L_80801310:
    // 0x80801310: jal         0x80088368
    // 0x80801314: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80801314: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_9:
    // 0x80801318: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080131C: bne         $at, $zero, L_808012B4
    if (ctx->r1 != 0) {
        // 0x80801320: addiu       $a2, $sp, 0x60
        ctx->r6 = ADD32(ctx->r29, 0X60);
            goto L_808012B4;
    }
    // 0x80801320: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
L_80801324:
    // 0x80801324: jal         0x800FC6B0
    // 0x80801328: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_10;
    // 0x80801328: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_10:
    // 0x8080132C: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80801330: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80801334: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801338: addiu       $s2, $s4, 0x28
    ctx->r18 = ADD32(ctx->r20, 0X28);
    // 0x8080133C: beq         $t5, $t6, L_8080138C
    if (ctx->r13 == ctx->r14) {
        // 0x80801340: addiu       $s0, $zero, 0x17F9
        ctx->r16 = ADD32(0, 0X17F9);
            goto L_8080138C;
    }
    // 0x80801340: addiu       $s0, $zero, 0x17F9
    ctx->r16 = ADD32(0, 0X17F9);
    // 0x80801344: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080134C: jal         0x800899A8
    // 0x80801350: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _sumultiscore_entrypoint_8(rdram, ctx);
        goto after_11;
    // 0x80801350: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_11:
    // 0x80801354: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80801358: beql        $v0, $t7, L_80801384
    if (ctx->r2 == ctx->r15) {
        // 0x8080135C: sw          $s1, 0x4($s4)
        MEM_W(0X4, ctx->r20) = ctx->r17;
            goto L_80801384;
    }
    goto skip_3;
    // 0x8080135C: sw          $s1, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r17;
    skip_3:
    // 0x80801360: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80801364:
    // 0x80801364: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801368: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080136C: jal         0x800899A8
    // 0x80801370: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _sumultiscore_entrypoint_8(rdram, ctx);
        goto after_12;
    // 0x80801370: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_12:
    // 0x80801374: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80801378: bnel        $v0, $t8, L_80801364
    if (ctx->r2 != ctx->r24) {
        // 0x8080137C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80801364;
    }
    goto skip_4;
    // 0x8080137C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x80801380: sw          $s1, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r17;
L_80801384:
    // 0x80801384: b           L_8080138C
    // 0x80801388: addiu       $s0, $zero, 0x17F8
    ctx->r16 = ADD32(0, 0X17F8);
        goto L_8080138C;
    // 0x80801388: addiu       $s0, $zero, 0x17F8
    ctx->r16 = ADD32(0, 0X17F8);
L_8080138C:
    // 0x8080138C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801390: jal         0x8008A090
    // 0x80801394: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiemulti_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x80801394: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80801398: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x8080139C: jal         0x80101FDC
    // 0x808013A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_14;
    // 0x808013A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x808013A4: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x808013A8: sw          $s0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r16;
    // 0x808013AC: sw          $t9, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r25;
    // 0x808013B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808013B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808013B8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808013BC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808013C0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808013C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808013C8: jr          $ra
    // 0x808013CC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x808013CC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void gccubeDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080045C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800460: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800464: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800468: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080046C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800470: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800474: jal         0x80088120
    // 0x80800478: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    _gcmapDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800478: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    after_0:
    // 0x8080047C: sh          $v0, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r2;
    // 0x80800480: lh          $a2, 0x3C($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X3C);
    // 0x80800484: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800488: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080048C: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x80800490: addiu       $s3, $s0, 0x4
    ctx->r19 = ADD32(ctx->r16, 0X4);
    // 0x80800494: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800498: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080049C: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x808004A0: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x808004A4: jal         0x800BEC4C
    // 0x808004A8: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    func_800BEC4C(rdram, ctx);
        goto after_1;
    // 0x808004A8: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x808004AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808004B0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808004B4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
L_808004B8:
    // 0x808004B8: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x808004BC: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x808004C0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808004C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808004C8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x808004CC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x808004D0: bne         $v1, $a0, L_808004B8
    if (ctx->r3 != ctx->r4) {
        // 0x808004D4: sw          $t9, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->r25;
            goto L_808004B8;
    }
    // 0x808004D4: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x808004D8: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x808004DC: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x808004E0: lw          $t1, 0x30($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X30);
    // 0x808004E4: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x808004E8: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808004EC: mflo        $v1
    ctx->r3 = lo;
    // 0x808004F0: sw          $v1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r3;
    // 0x808004F4: nop

    // 0x808004F8: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808004FC: mflo        $a1
    ctx->r5 = lo;
    // 0x80800500: sw          $a1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r5;
    // 0x80800504: jal         0x8001ACCC
    // 0x80800508: sll         $a0, $a1, 3
    ctx->r4 = S32(ctx->r5 << 3);
    heap_alloc(rdram, ctx);
        goto after_2;
    // 0x80800508: sll         $a0, $a1, 3
    ctx->r4 = S32(ctx->r5 << 3);
    after_2:
    // 0x8080050C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80800510: jal         0x8001ACCC
    // 0x80800514: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    heap_alloc(rdram, ctx);
        goto after_3;
    // 0x80800514: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    after_3:
    // 0x80800518: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x8080051C: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
    // 0x80800520: addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // 0x80800524: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x80800528: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x8080052C: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
    // 0x80800530: slt         $at, $t3, $t2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80800534: bnel        $at, $zero, L_80800618
    if (ctx->r1 != 0) {
        // 0x80800538: addiu       $a0, $s0, 0x34
        ctx->r4 = ADD32(ctx->r16, 0X34);
            goto L_80800618;
    }
    goto skip_0;
    // 0x80800538: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    skip_0:
    // 0x8080053C: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
L_80800540:
    // 0x80800540: sw          $t5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r13;
    // 0x80800544: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80800548: slt         $at, $t6, $t5
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8080054C: bnel        $at, $zero, L_808005FC
    if (ctx->r1 != 0) {
        // 0x80800550: lw          $t1, 0x4C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X4C);
            goto L_808005FC;
    }
    goto skip_1;
    // 0x80800550: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x80800554: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_80800558:
    // 0x80800558: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x8080055C: lw          $t9, 0x18($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X18);
    // 0x80800560: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80800564: bne         $at, $zero, L_808005DC
    if (ctx->r1 != 0) {
        // 0x80800568: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808005DC;
    }
    // 0x80800568: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8080056C:
    // 0x8080056C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800570: jal         0x800EFB58
    // 0x80800574: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EFB58(rdram, ctx);
        goto after_4;
    // 0x80800574: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_4:
    // 0x80800578: lw          $t1, 0x20($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X20);
    // 0x8080057C: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80800580: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80800584: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80800588: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080058C: lw          $t1, 0x1C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C);
    // 0x80800590: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80800594: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800598: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8080059C: mflo        $t3
    ctx->r11 = lo;
    // 0x808005A0: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x808005A4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x808005A8: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808005AC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x808005B0: mflo        $t2
    ctx->r10 = lo;
    // 0x808005B4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x808005B8: jal         0x800E9E4C
    // 0x808005BC: addu        $a0, $t9, $t3
    ctx->r4 = ADD32(ctx->r25, ctx->r11);
    func_800E9E4C(rdram, ctx);
        goto after_5;
    // 0x808005BC: addu        $a0, $t9, $t3
    ctx->r4 = ADD32(ctx->r25, ctx->r11);
    after_5:
    // 0x808005C0: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x808005C4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x808005C8: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    // 0x808005CC: lw          $t7, 0x18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18);
    // 0x808005D0: slt         $at, $t7, $t5
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x808005D4: beql        $at, $zero, L_8080056C
    if (ctx->r1 == 0) {
        // 0x808005D8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8080056C;
    }
    goto skip_2;
    // 0x808005D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_2:
L_808005DC:
    // 0x808005DC: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x808005E0: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x808005E4: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x808005E8: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
    // 0x808005EC: slt         $at, $t0, $t8
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x808005F0: beql        $at, $zero, L_80800558
    if (ctx->r1 == 0) {
        // 0x808005F4: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_80800558;
    }
    goto skip_3;
    // 0x808005F4: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_3:
    // 0x808005F8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
L_808005FC:
    // 0x808005FC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80800600: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x80800604: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x80800608: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8080060C: beql        $at, $zero, L_80800540
    if (ctx->r1 == 0) {
        // 0x80800610: lw          $t5, 0x8($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X8);
            goto L_80800540;
    }
    goto skip_4;
    // 0x80800610: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    skip_4:
    // 0x80800614: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
L_80800618:
    // 0x80800618: jal         0x800E9E4C
    // 0x8080061C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800E9E4C(rdram, ctx);
        goto after_6;
    // 0x8080061C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800620: jal         0x800EA05C
    // 0x80800624: nop

    func_800EA05C(rdram, ctx);
        goto after_7;
    // 0x80800624: nop

    after_7:
    // 0x80800628: addiu       $at, $zero, 0xD7
    ctx->r1 = ADD32(0, 0XD7);
    // 0x8080062C: bne         $v0, $at, L_80800640
    if (ctx->r2 != ctx->r1) {
        // 0x80800630: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_80800640;
    }
    // 0x80800630: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800634: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800638: b           L_8080064C
    // 0x8080063C: nop

        goto L_8080064C;
    // 0x8080063C: nop

L_80800640:
    // 0x80800640: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800644: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800648: nop

L_8080064C:
    // 0x8080064C: jal         0x800CD230
    // 0x80800650: nop

    func_800CD230(rdram, ctx);
        goto after_8;
    // 0x80800650: nop

    after_8:
    // 0x80800654: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80800658: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8080065C: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80800660: addiu       $a2, $a2, -0x2ABC
    ctx->r6 = ADD32(ctx->r6, -0X2ABC);
    // 0x80800664: addiu       $a1, $a1, -0x2C58
    ctx->r5 = ADD32(ctx->r5, -0X2C58);
    // 0x80800668: jal         0x800C6A08
    // 0x8080066C: addiu       $a0, $a0, -0x2DC4
    ctx->r4 = ADD32(ctx->r4, -0X2DC4);
    func_800C6A08(rdram, ctx);
        goto after_9;
    // 0x8080066C: addiu       $a0, $a0, -0x2DC4
    ctx->r4 = ADD32(ctx->r4, -0X2DC4);
    after_9:
    // 0x80800670: jal         0x800CE2DC
    // 0x80800674: nop

    func_800CE2DC(rdram, ctx);
        goto after_10;
    // 0x80800674: nop

    after_10:
    // 0x80800678: jal         0x800E9708
    // 0x8080067C: nop

    func_800E9708(rdram, ctx);
        goto after_11;
    // 0x8080067C: nop

    after_11:
    // 0x80800680: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800684: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800688: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080068C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800690: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800694: jr          $ra
    // 0x80800698: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80800698: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800A355C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A355C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A3560: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A3564: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A3568: jal         0x8009C150
    // 0x800A356C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009C150(rdram, ctx);
        goto after_0;
    // 0x800A356C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800A3570: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800A3574: jal         0x800F3ED0
    // 0x800A3578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F3ED0(rdram, ctx);
        goto after_1;
    // 0x800A3578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A357C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800A3580: jal         0x8008E078
    // 0x800A3584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_2;
    // 0x800A3584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800A3588: bnel        $v0, $zero, L_800A35D8
    if (ctx->r2 != 0) {
        // 0x800A358C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A35D8;
    }
    goto skip_0;
    // 0x800A358C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800A3590: jal         0x8008E35C
    // 0x800A3594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_3;
    // 0x800A3594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800A3598: bne         $v0, $zero, L_800A35D4
    if (ctx->r2 != 0) {
        // 0x800A359C: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_800A35D4;
    }
    // 0x800A359C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A35A0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A35A4: bne         $t6, $at, L_800A35C0
    if (ctx->r14 != ctx->r1) {
        // 0x800A35A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A35C0;
    }
    // 0x800A35A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A35AC: jal         0x8008EF3C
    // 0x800A35B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EF3C(rdram, ctx);
        goto after_4;
    // 0x800A35B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800A35B4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A35B8: bnel        $v0, $at, L_800A35D8
    if (ctx->r2 != ctx->r1) {
        // 0x800A35BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A35D8;
    }
    goto skip_1;
    // 0x800A35BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_800A35C0:
    // 0x800A35C0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800A35C4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A35C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A35CC: bne         $t7, $at, L_800A35E8
    if (ctx->r15 != ctx->r1) {
        // 0x800A35D0: nop
    
            goto L_800A35E8;
    }
    // 0x800A35D0: nop

L_800A35D4:
    // 0x800A35D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800A35D8:
    // 0x800A35D8: jal         0x800A3550
    // 0x800A35DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A3550(rdram, ctx);
        goto after_5;
    // 0x800A35DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x800A35E0: b           L_800A35F4
    // 0x800A35E4: lw          $v0, 0xA0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA0);
        goto L_800A35F4;
    // 0x800A35E4: lw          $v0, 0xA0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA0);
L_800A35E8:
    // 0x800A35E8: jal         0x800A3550
    // 0x800A35EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800A3550(rdram, ctx);
        goto after_6;
    // 0x800A35EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x800A35F0: lw          $v0, 0xA0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA0);
L_800A35F4:
    // 0x800A35F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A35F8: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A35FC: lbu         $t8, 0x50($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X50);
    // 0x800A3600: bnel        $t8, $at, L_800A3620
    if (ctx->r24 != ctx->r1) {
        // 0x800A3604: lwc1        $f8, 0x4C($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X4C);
            goto L_800A3620;
    }
    goto skip_2;
    // 0x800A3604: lwc1        $f8, 0x4C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4C);
    skip_2:
    // 0x800A3608: lwc1        $f4, 0x4C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x800A360C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800A3610: nop

    // 0x800A3614: bc1tl       L_800A3634
    if (c1cs) {
        // 0x800A3618: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800A3634;
    }
    goto skip_3;
    // 0x800A3618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800A361C: lwc1        $f8, 0x4C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4C);
L_800A3620:
    // 0x800A3620: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    // 0x800A3624: lw          $t9, 0xA0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XA0);
    // 0x800A3628: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A362C: swc1        $f10, 0x4C($t9)
    MEM_W(0X4C, ctx->r25) = ctx->f10.u32l;
    // 0x800A3630: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A3634:
    // 0x800A3634: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A3638: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A363C: jr          $ra
    // 0x800A3640: nop

    return;
    // 0x800A3640: nop

;}
RECOMP_FUNC void sumumbofx_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801278: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080127C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801280: lbu         $t6, 0x60($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X60);
    // 0x80801284: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80801288: andi        $t7, $t6, 0xFF01
    ctx->r15 = ctx->r14 & 0XFF01;
    // 0x8080128C: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x80801290: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80801294: jal         0x8080134C
    // 0x80801298: sb          $t8, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r24;
    sumumbofx_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80801298: sb          $t8, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r24;
    after_0:
    // 0x8080129C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808012A4: jr          $ra
    // 0x808012A8: nop

    return;
    // 0x808012A8: nop

;}
