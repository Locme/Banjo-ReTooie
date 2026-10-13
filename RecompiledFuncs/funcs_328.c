#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80101D0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101D0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101D14: jal         0x80104248
    // 0x80101D18: nop

    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80101D18: nop

    after_0:
    // 0x80101D1C: beq         $v0, $zero, L_80101D34
    if (ctx->r2 == 0) {
        // 0x80101D20: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101D34;
    }
    // 0x80101D20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101D24: jal         0x8008B2AC
    // 0x80101D28: nop

    func_8008B2AC(rdram, ctx);
        goto after_1;
    // 0x80101D28: nop

    after_1:
    // 0x80101D2C: b           L_80101D40
    // 0x80101D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80101D40;
    // 0x80101D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80101D34:
    // 0x80101D34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80101D38: nop

    // 0x80101D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80101D40:
    // 0x80101D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101D44: jr          $ra
    // 0x80101D48: nop

    return;
    // 0x80101D48: nop

;}
RECOMP_FUNC void func_800A5550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5558: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A555C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A5560: lhu         $a0, 0x1A($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X1A);
    // 0x800A5564: srl         $t7, $a0, 5
    ctx->r15 = S32(U32(ctx->r4) >> 5);
    // 0x800A5568: jal         0x800A93E4
    // 0x800A556C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800A93E4(rdram, ctx);
        goto after_0;
    // 0x800A556C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x800A5570: jal         0x80110014
    // 0x800A5574: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_1;
    // 0x800A5574: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800A5578: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A557C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800A5580: jal         0x800893A8
    // 0x800A5584: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    _ncbaspline_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x800A5584: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800A5588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A558C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5590: jr          $ra
    // 0x800A5594: nop

    return;
    // 0x800A5594: nop

;}
RECOMP_FUNC void _bssnowball_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A30: syscall     87
    recomp_syscall_handler(rdram, ctx, 0x80083A30);
    return;
    // 0x80083A34: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80801AF8_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AF8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801AFC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2658, 0X2130) << 16);
    // 0x80801B00: lh          $t6, 0x2130($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(2658, 0X2130));
    // 0x80801B04: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80801B08: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80801B0C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80801B10: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80801B14: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80801B18: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801B1C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801B20: beq         $s1, $t6, L_80801B74
    if (ctx->r17 == ctx->r14) {
        // 0x80801B24: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80801B74;
    }
    // 0x80801B24: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80801B28: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2658, 0X2130) << 16);
    // 0x80801B2C: addiu       $s0, $t7, 0x2130
    ctx->r16 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2658, 0X2130));
    // 0x80801B30: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_80801B34:
    // 0x80801B34: jal         0x800D035C
    // 0x80801B38: nop

    func_800D035C(rdram, ctx);
        goto after_0;
    // 0x80801B38: nop

    after_0:
    // 0x80801B3C: beq         $v0, $zero, L_80801B64
    if (ctx->r2 == 0) {
        // 0x80801B40: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80801B64;
    }
    // 0x80801B40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801B44: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    // 0x80801B48: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x80801B4C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80801B50: jal         0x8080190C
    // 0x80801B54: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_8080190C_gcnewpause(rdram, ctx);
        goto after_1;
    // 0x80801B54: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_1:
    // 0x80801B58: beql        $v0, $zero, L_80801B68
    if (ctx->r2 == 0) {
        // 0x80801B5C: lh          $a0, 0x6($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X6);
            goto L_80801B68;
    }
    goto skip_0;
    // 0x80801B5C: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
    skip_0:
    // 0x80801B60: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80801B64:
    // 0x80801B64: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
L_80801B68:
    // 0x80801B68: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x80801B6C: bne         $s1, $a0, L_80801B34
    if (ctx->r17 != ctx->r4) {
        // 0x80801B70: nop
    
            goto L_80801B34;
    }
    // 0x80801B70: nop

L_80801B74:
    // 0x80801B74: jal         0x800DAD10
    // 0x80801B78: nop

    func_800DAD10(rdram, ctx);
        goto after_2;
    // 0x80801B78: nop

    after_2:
    // 0x80801B7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801B80: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80801B84: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80801B88: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80801B8C: jal         0x8080190C
    // 0x80801B90: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_8080190C_gcnewpause(rdram, ctx);
        goto after_3;
    // 0x80801B90: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_3:
    // 0x80801B94: beq         $v0, $zero, L_80801BA0
    if (ctx->r2 == 0) {
        // 0x80801B98: nop
    
            goto L_80801BA0;
    }
    // 0x80801B98: nop

    // 0x80801B9C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80801BA0:
    // 0x80801BA0: jal         0x80801C3C
    // 0x80801BA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80801C3C_gcnewpause(rdram, ctx);
        goto after_4;
    // 0x80801BA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80801BA8: beq         $v0, $zero, L_80801BD0
    if (ctx->r2 == 0) {
        // 0x80801BAC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80801BD0;
    }
    // 0x80801BAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801BB0: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80801BB4: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80801BB8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80801BBC: jal         0x8080190C
    // 0x80801BC0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_8080190C_gcnewpause(rdram, ctx);
        goto after_5;
    // 0x80801BC0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_5:
    // 0x80801BC4: beql        $v0, $zero, L_80801BD4
    if (ctx->r2 == 0) {
        // 0x80801BC8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80801BD4;
    }
    goto skip_1;
    // 0x80801BC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80801BCC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80801BD0:
    // 0x80801BD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80801BD4:
    // 0x80801BD4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80801BD8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80801BDC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801BE0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801BE4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80801BE8: jr          $ra
    // 0x80801BEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801BEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80104148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104148: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8010414C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80104150: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80104154: addiu       $t7, $t7, 0x6D88
    ctx->r15 = ADD32(ctx->r15, 0X6D88);
    // 0x80104158: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8010415C: jr          $ra
    // 0x80104160: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    return;
    // 0x80104160: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80104164: nop

    // 0x80104168: nop

    // 0x8010416C: nop

;}
RECOMP_FUNC void func_80110E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110E00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80110E04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80110E08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80110E0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80110E10: jal         0x80114D98
    // 0x80110E14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80114D98(rdram, ctx);
        goto after_0;
    // 0x80110E14: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80110E18: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80110E1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80110E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80110E24: beq         $a1, $zero, L_80110EC8
    if (ctx->r5 == 0) {
        // 0x80110E28: nop
    
            goto L_80110EC8;
    }
    // 0x80110E28: nop

    // 0x80110E2C: beq         $a1, $v1, L_80110ED8
    if (ctx->r5 == ctx->r3) {
        // 0x80110E30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80110ED8;
    }
    // 0x80110E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80110E34: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80110E38: bne         $a1, $a0, L_80110EE8
    if (ctx->r5 != ctx->r4) {
        // 0x80110E3C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80110EE8;
    }
    // 0x80110E3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80110E40: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x80110E44: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80110E48: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80110E4C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80110E50: lh          $v0, 0x47AE($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X47AE);
    // 0x80110E54: beq         $v0, $v1, L_80110E6C
    if (ctx->r2 == ctx->r3) {
        // 0x80110E58: nop
    
            goto L_80110E6C;
    }
    // 0x80110E58: nop

    // 0x80110E5C: beq         $v0, $a0, L_80110E88
    if (ctx->r2 == ctx->r4) {
        // 0x80110E60: nop
    
            goto L_80110E88;
    }
    // 0x80110E60: nop

    // 0x80110E64: b           L_80110E9C
    // 0x80110E68: nop

        goto L_80110E9C;
    // 0x80110E68: nop

L_80110E6C:
    // 0x80110E6C: jal         0x800F5AE0
    // 0x80110E70: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    func_800F5AE0(rdram, ctx);
        goto after_1;
    // 0x80110E70: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    after_1:
    // 0x80110E74: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80110E78: jal         0x80111198
    // 0x80110E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80111198(rdram, ctx);
        goto after_2;
    // 0x80110E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80110E80: b           L_80110E9C
    // 0x80110E84: nop

        goto L_80110E9C;
    // 0x80110E84: nop

L_80110E88:
    // 0x80110E88: jal         0x80115E88
    // 0x80110E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80115E88(rdram, ctx);
        goto after_3;
    // 0x80110E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80110E90: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80110E94: jal         0x80111198
    // 0x80110E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80111198(rdram, ctx);
        goto after_4;
    // 0x80110E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80110E9C:
    // 0x80110E9C: jal         0x801112B0
    // 0x80110EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801112B0(rdram, ctx);
        goto after_5;
    // 0x80110EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80110EA4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80110EA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80110EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80110EB0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80110EB4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80110EB8: jal         0x80111154
    // 0x80110EBC: nop

    func_80111154(rdram, ctx);
        goto after_6;
    // 0x80110EBC: nop

    after_6:
    // 0x80110EC0: b           L_80110EEC
    // 0x80110EC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80110EEC;
    // 0x80110EC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80110EC8:
    // 0x80110EC8: jal         0x801111D0
    // 0x80110ECC: lui         $a1, 0xC234
    ctx->r5 = S32(0XC234 << 16);
    func_801111D0(rdram, ctx);
        goto after_7;
    // 0x80110ECC: lui         $a1, 0xC234
    ctx->r5 = S32(0XC234 << 16);
    after_7:
    // 0x80110ED0: b           L_80110EEC
    // 0x80110ED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80110EEC;
    // 0x80110ED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80110ED8:
    // 0x80110ED8: jal         0x801111D0
    // 0x80110EDC: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    func_801111D0(rdram, ctx);
        goto after_8;
    // 0x80110EDC: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    after_8:
    // 0x80110EE0: b           L_80110EEC
    // 0x80110EE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80110EEC;
    // 0x80110EE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80110EE8:
    // 0x80110EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80110EEC:
    // 0x80110EEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80110EF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80110EF4: jr          $ra
    // 0x80110EF8: nop

    return;
    // 0x80110EF8: nop

;}
RECOMP_FUNC void func_808014FC_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801500: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801504: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801508: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080150C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801514: jal         0x80100094
    // 0x80801518: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801518: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080151C: lbu         $t6, 0x74($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X74);
    // 0x80801520: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80801524: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x80801528: sb          $t7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r15;
    // 0x8080152C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80801530: addiu       $t9, $t8, -0x11D7
    ctx->r25 = ADD32(ctx->r24, -0X11D7);
    // 0x80801534: sltiu       $at, $t9, 0x15
    ctx->r1 = ctx->r25 < 0X15 ? 1 : 0;
    // 0x80801538: beq         $at, $zero, L_808016E8
    if (ctx->r1 == 0) {
        // 0x8080153C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808016E8;
    }
    // 0x8080153C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80801540: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1584, 0X1934) << 16);
    // 0x80801544: addu        $at, $at, $t9
    gpr jr_addend_8080154C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80801548: lw          $t9, 0x1934($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1584, 0X1934));
    // 0x8080154C: jr          $t9
    // 0x80801550: nop

    switch (jr_addend_8080154C >> 2) {
        case 0: goto L_80801554; break;
        case 1: goto L_808015D8; break;
        case 2: goto L_80801588; break;
        case 3: goto L_808015B0; break;
        case 4: goto L_808015F4; break;
        case 5: goto L_808016E8; break;
        case 6: goto L_808016E8; break;
        case 7: goto L_808016E8; break;
        case 8: goto L_808016E8; break;
        case 9: goto L_808016E8; break;
        case 10: goto L_808016E8; break;
        case 11: goto L_808016E8; break;
        case 12: goto L_808016E8; break;
        case 13: goto L_808016E8; break;
        case 14: goto L_808016E8; break;
        case 15: goto L_808016E0; break;
        case 16: goto L_808016E8; break;
        case 17: goto L_808016E8; break;
        case 18: goto L_808016E8; break;
        case 19: goto L_8080167C; break;
        case 20: goto L_808015E4; break;
        default: switch_error(__func__, 0x8080154C, 0x80801934);
    }
    // 0x80801550: nop

L_80801554:
    // 0x80801554: blez        $a2, L_80801574
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80801558: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801574;
    }
    // 0x80801558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080155C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801560: addiu       $a1, $zero, 0x11D8
    ctx->r5 = ADD32(0, 0X11D8);
    // 0x80801564: jal         0x808000DC
    // 0x80801568: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_808000DC_chnewmumbo(rdram, ctx);
        goto after_1;
    // 0x80801568: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_1:
    // 0x8080156C: b           L_808016EC
    // 0x80801570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016EC;
    // 0x80801570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801574:
    // 0x80801574: addiu       $a1, $zero, 0x11D9
    ctx->r5 = ADD32(0, 0X11D9);
    // 0x80801578: jal         0x808000DC
    // 0x8080157C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_808000DC_chnewmumbo(rdram, ctx);
        goto after_2;
    // 0x8080157C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_2:
    // 0x80801580: b           L_808016EC
    // 0x80801584: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016EC;
    // 0x80801584: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801588:
    // 0x80801588: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080158C: jal         0x800EE7F8
    // 0x80801590: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80801590: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80801594: jal         0x808007B0
    // 0x80801598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007B0_chnewmumbo(rdram, ctx);
        goto after_4;
    // 0x80801598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080159C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015A0: jal         0x80800264
    // 0x808015A4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_5;
    // 0x808015A4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_5:
    // 0x808015A8: b           L_808016EC
    // 0x808015AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016EC;
    // 0x808015AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808015B0:
    // 0x808015B0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808015B4: jal         0x800EE7F8
    // 0x808015B8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x808015B8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x808015BC: jal         0x808007B0
    // 0x808015C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007B0_chnewmumbo(rdram, ctx);
        goto after_7;
    // 0x808015C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808015C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015C8: jal         0x80800264
    // 0x808015CC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_8;
    // 0x808015CC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_8:
    // 0x808015D0: b           L_808016EC
    // 0x808015D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016EC;
    // 0x808015D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808015D8:
    // 0x808015D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808015DC: b           L_808016E8
    // 0x808015E0: sb          $t0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r8;
        goto L_808016E8;
    // 0x808015E0: sb          $t0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r8;
L_808015E4:
    // 0x808015E4: jal         0x8080009C
    // 0x808015E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chnewmumbo(rdram, ctx);
        goto after_9;
    // 0x808015E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808015EC: b           L_808016EC
    // 0x808015F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016EC;
    // 0x808015F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808015F4:
    // 0x808015F4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808015F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808015FC: srl         $t1, $v0, 10
    ctx->r9 = S32(U32(ctx->r2) >> 10);
    // 0x80801600: beq         $t1, $at, L_8080163C
    if (ctx->r9 == ctx->r1) {
        // 0x80801604: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080163C;
    }
    // 0x80801604: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801608: bnel        $t1, $at, L_808016EC
    if (ctx->r9 != ctx->r1) {
        // 0x8080160C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808016EC;
    }
    goto skip_0;
    // 0x8080160C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801610: blez        $a2, L_80801628
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80801614: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801628;
    }
    // 0x80801614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801618: jal         0x80800878
    // 0x8080161C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800878_chnewmumbo(rdram, ctx);
        goto after_10;
    // 0x8080161C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801620: b           L_808016EC
    // 0x80801624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016EC;
    // 0x80801624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801628:
    // 0x80801628: addiu       $a1, $zero, 0x11EA
    ctx->r5 = ADD32(0, 0X11EA);
    // 0x8080162C: jal         0x808000DC
    // 0x80801630: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_808000DC_chnewmumbo(rdram, ctx);
        goto after_11;
    // 0x80801630: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_11:
    // 0x80801634: b           L_808016EC
    // 0x80801638: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016EC;
    // 0x80801638: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080163C:
    // 0x8080163C: blez        $a2, L_80801668
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80801640: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801668;
    }
    // 0x80801640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801648: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080164C: jal         0x80800000
    // 0x80801650: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800000_chnewmumbo(rdram, ctx);
        goto after_12;
    // 0x80801650: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x80801654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801658: jal         0x80800264
    // 0x8080165C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_13;
    // 0x8080165C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_13:
    // 0x80801660: b           L_808016EC
    // 0x80801664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016EC;
    // 0x80801664: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801668:
    // 0x80801668: addiu       $a1, $zero, 0x11EA
    ctx->r5 = ADD32(0, 0X11EA);
    // 0x8080166C: jal         0x808000DC
    // 0x80801670: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_808000DC_chnewmumbo(rdram, ctx);
        goto after_14;
    // 0x80801670: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_14:
    // 0x80801674: b           L_808016EC
    // 0x80801678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016EC;
    // 0x80801678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080167C:
    // 0x8080167C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80801680: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801688: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x8080168C: beq         $t2, $at, L_808016A4
    if (ctx->r10 == ctx->r1) {
        // 0x80801690: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808016A4;
    }
    // 0x80801690: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801694: beq         $t2, $at, L_808016BC
    if (ctx->r10 == ctx->r1) {
        // 0x80801698: nop
    
            goto L_808016BC;
    }
    // 0x80801698: nop

    // 0x8080169C: b           L_808016EC
    // 0x808016A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016EC;
    // 0x808016A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808016A4:
    // 0x808016A4: jal         0x80800264
    // 0x808016A8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_15;
    // 0x808016A8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_15:
    // 0x808016AC: jal         0x808007B0
    // 0x808016B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007B0_chnewmumbo(rdram, ctx);
        goto after_16;
    // 0x808016B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808016B4: b           L_808016EC
    // 0x808016B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016EC;
    // 0x808016B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808016BC:
    // 0x808016BC: jal         0x8080009C
    // 0x808016C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chnewmumbo(rdram, ctx);
        goto after_17;
    // 0x808016C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808016C4: jal         0x808007B0
    // 0x808016C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007B0_chnewmumbo(rdram, ctx);
        goto after_18;
    // 0x808016C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808016CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016D0: jal         0x80800264
    // 0x808016D4: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_80800264_chnewmumbo(rdram, ctx);
        goto after_19;
    // 0x808016D4: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_19:
    // 0x808016D8: b           L_808016EC
    // 0x808016DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808016EC;
    // 0x808016DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808016E0:
    // 0x808016E0: jal         0x8080009C
    // 0x808016E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080009C_chnewmumbo(rdram, ctx);
        goto after_20;
    // 0x808016E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
L_808016E8:
    // 0x808016E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808016EC:
    // 0x808016EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808016F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808016F4: jr          $ra
    // 0x808016F8: nop

    return;
    // 0x808016F8: nop

;}
RECOMP_FUNC void _chmineproplight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086970: syscall     402
    recomp_syscall_handler(rdram, ctx, 0x80086970);
    return;
    // 0x80086974: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800D6D68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6D68: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800D6D6C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800D6D70: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D6D74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D6D78: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800D6D7C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D6D80: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D6D84: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D6D88: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800D6D8C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800D6D90: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800D6D94: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800D6D98: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800D6D9C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800D6DA0: addiu       $s6, $s6, -0x419E
    ctx->r22 = ADD32(ctx->r22, -0X419E);
    // 0x800D6DA4: addiu       $s3, $s3, -0x4800
    ctx->r19 = ADD32(ctx->r19, -0X4800);
    // 0x800D6DA8: addiu       $s0, $s0, -0x41A0
    ctx->r16 = ADD32(ctx->r16, -0X41A0);
    // 0x800D6DAC: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    // 0x800D6DB0: addiu       $s5, $zero, 0x3FFF
    ctx->r21 = ADD32(0, 0X3FFF);
    // 0x800D6DB4: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
L_800D6DB8:
    // 0x800D6DB8: multu       $v0, $s4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6DBC: mflo        $t6
    ctx->r14 = lo;
    // 0x800D6DC0: addu        $a0, $s3, $t6
    ctx->r4 = ADD32(ctx->r19, ctx->r14);
    // 0x800D6DC4: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x800D6DC8: srl         $t8, $t7, 18
    ctx->r24 = S32(U32(ctx->r15) >> 18);
    // 0x800D6DCC: beql        $s5, $t8, L_800D6DF8
    if (ctx->r21 == ctx->r24) {
        // 0x800D6DD0: addiu       $t1, $v0, 0x1
        ctx->r9 = ADD32(ctx->r2, 0X1);
            goto L_800D6DF8;
    }
    goto skip_0;
    // 0x800D6DD0: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800D6DD4: lbu         $t9, 0xA($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XA);
    // 0x800D6DD8: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x800D6DDC: bnel        $t0, $zero, L_800D6DF8
    if (ctx->r8 != 0) {
        // 0x800D6DE0: addiu       $t1, $v0, 0x1
        ctx->r9 = ADD32(ctx->r2, 0X1);
            goto L_800D6DF8;
    }
    goto skip_1;
    // 0x800D6DE0: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x800D6DE4: jal         0x800D6550
    // 0x800D6DE8: nop

    func_800D6550(rdram, ctx);
        goto after_0;
    // 0x800D6DE8: nop

    after_0:
    // 0x800D6DEC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D6DF0: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x800D6DF4: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
L_800D6DF8:
    // 0x800D6DF8: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x800D6DFC: lh          $t2, 0x0($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X0);
    // 0x800D6E00: lh          $t3, 0x0($s6)
    ctx->r11 = MEM_H(ctx->r22, 0X0);
    // 0x800D6E04: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D6E08: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800D6E0C: bnel        $at, $zero, L_800D6E1C
    if (ctx->r1 != 0) {
        // 0x800D6E10: slti        $at, $s1, 0x20
        ctx->r1 = SIGNED(ctx->r17) < 0X20 ? 1 : 0;
            goto L_800D6E1C;
    }
    goto skip_2;
    // 0x800D6E10: slti        $at, $s1, 0x20
    ctx->r1 = SIGNED(ctx->r17) < 0X20 ? 1 : 0;
    skip_2:
    // 0x800D6E14: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x800D6E18: slti        $at, $s1, 0x20
    ctx->r1 = SIGNED(ctx->r17) < 0X20 ? 1 : 0;
L_800D6E1C:
    // 0x800D6E1C: beq         $at, $zero, L_800D6E2C
    if (ctx->r1 == 0) {
        // 0x800D6E20: slti        $at, $s2, 0x8
        ctx->r1 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
            goto L_800D6E2C;
    }
    // 0x800D6E20: slti        $at, $s2, 0x8
    ctx->r1 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
    // 0x800D6E24: bnel        $at, $zero, L_800D6DB8
    if (ctx->r1 != 0) {
        // 0x800D6E28: lh          $v0, 0x0($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X0);
            goto L_800D6DB8;
    }
    goto skip_3;
    // 0x800D6E28: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    skip_3:
L_800D6E2C:
    // 0x800D6E2C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800D6E30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D6E34: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D6E38: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D6E3C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D6E40: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D6E44: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800D6E48: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800D6E4C: jr          $ra
    // 0x800D6E50: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800D6E50: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _suquiz_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A898: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A898);
    return;
    // 0x8008A89C: addi        $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
;}
RECOMP_FUNC void func_808006F0_cheggsplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808006FC: jal         0x800B53A4
    // 0x80800700: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800700: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x80800704: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800708: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080070C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800710: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x80800714: addiu       $v0, $zero, 0x9B1
    ctx->r2 = ADD32(0, 0X9B1);
    // 0x80800718: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x8080071C: bne         $t8, $at, L_8080072C
    if (ctx->r24 != ctx->r1) {
        // 0x80800720: nop
    
            goto L_8080072C;
    }
    // 0x80800720: nop

    // 0x80800724: b           L_8080072C
    // 0x80800728: addiu       $v0, $zero, 0x875
    ctx->r2 = ADD32(0, 0X875);
        goto L_8080072C;
    // 0x80800728: addiu       $v0, $zero, 0x875
    ctx->r2 = ADD32(0, 0X875);
L_8080072C:
    // 0x8080072C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800730: jal         0x800BA670
    // 0x80800734: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800BA670(rdram, ctx);
        goto after_1;
    // 0x80800734: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800738: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8080073C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2176, 0X9E8) << 16);
    // 0x80800740: addiu       $t9, $t9, 0x9E8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2176, 0X9E8));
    // 0x80800744: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800748: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080074C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800750: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800754: jal         0x800BABB8
    // 0x80800758: lui         $a3, 0x3E80
    ctx->r7 = S32(0X3E80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800758: lui         $a3, 0x3E80
    ctx->r7 = S32(0X3E80 << 16);
    after_2:
    // 0x8080075C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800760: jal         0x800BA22C
    // 0x80800764: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80800764: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80800768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080076C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800770: jr          $ra
    // 0x80800774: nop

    return;
    // 0x80800774: nop

;}
RECOMP_FUNC void _basudie_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085220: syscall     155
    recomp_syscall_handler(rdram, ctx, 0x80085220);
    return;
    // 0x80085224: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800BA930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BA934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BA93C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BA940: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800BA944: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800BA948: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800BA94C: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x800BA950: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x800BA954: sra         $a3, $t0, 16
    ctx->r7 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800BA958: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800BA95C: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800BA960: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x800BA964: jal         0x800EFA6C
    // 0x800BA968: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_800EFA6C(rdram, ctx);
        goto after_0;
    // 0x800BA968: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x800BA96C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BA970: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x800BA974: lh          $a2, 0x2E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X2E);
    // 0x800BA978: lh          $a3, 0x32($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X32);
    // 0x800BA97C: jal         0x800EFA6C
    // 0x800BA980: addiu       $a0, $a0, 0xCA
    ctx->r4 = ADD32(ctx->r4, 0XCA);
    func_800EFA6C(rdram, ctx);
        goto after_1;
    // 0x800BA980: addiu       $a0, $a0, 0xCA
    ctx->r4 = ADD32(ctx->r4, 0XCA);
    after_1:
    // 0x800BA984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BA988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BA98C: jr          $ra
    // 0x800BA990: nop

    return;
    // 0x800BA990: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087DC8: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087DC8);
    return;
    // 0x80087DCC: addi        $t0, $zero, 0x98
    ctx->r8 = ADD32(0, 0X98);
;}
RECOMP_FUNC void func_80800E50_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E58: lwc1        $f14, 0x48($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800E5C: lwc1        $f12, 0x54($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X54);
    // 0x80800E60: jal         0x800F1DCC
    // 0x80800E64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F1DCC(rdram, ctx);
        goto after_0;
    // 0x80800E64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E68: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80800E6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800E70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E74: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800E78: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800E7C: nop

    // 0x80800E80: bc1t        L_80800E9C
    if (c1cs) {
        // 0x80800E84: nop
    
            goto L_80800E9C;
    }
    // 0x80800E84: nop

    // 0x80800E88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800E8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800E90: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800E94: nop

    // 0x80800E98: bc1f        L_80800EBC
    if (!c1cs) {
        // 0x80800E9C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1676, 0X3DE4) << 16);
            goto L_80800EBC;
    }
L_80800E9C:
    // 0x80800E9C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3DE4) << 16);
    // 0x80800EA0: lwc1        $f10, 0x3DE4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3DE4));
    // 0x80800EA4: lwc1        $f8, 0x48($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800EA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800EAC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800EB0: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80800EB4: b           L_80800EBC
    // 0x80800EB8: swc1        $f18, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f18.u32l;
        goto L_80800EBC;
    // 0x80800EB8: swc1        $f18, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f18.u32l;
L_80800EBC:
    // 0x80800EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800EC4: jr          $ra
    // 0x80800EC8: nop

    return;
    // 0x80800EC8: nop

;}
RECOMP_FUNC void bahitspline_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x80800014: jal         0x80095870
    // 0x80800018: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    func_80095870(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_0:
    // 0x8080001C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800020: jal         0x8009C128
    // 0x80800024: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x80800024: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_1:
    // 0x80800028: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8080002C: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80800030: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80800034: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80800038: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080003C: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80800040: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800044: jal         0x800EFA4C
    // 0x80800048: nop

    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80800048: nop

    after_2:
    // 0x8080004C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800050: jal         0x800EE7F8
    // 0x80800054: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800054: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_3:
    // 0x80800058: jal         0x8009588C
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009588C(rdram, ctx);
        goto after_4;
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800060: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800064: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800068: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8080006C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x80800070: jal         0x800C6C94
    // 0x80800074: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_800C6C94(rdram, ctx);
        goto after_5;
    // 0x80800074: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_5:
    // 0x80800078: beq         $v0, $zero, L_80800100
    if (ctx->r2 == 0) {
        // 0x8080007C: lwc1        $f10, 0x74($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
            goto L_80800100;
    }
    // 0x8080007C: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800080: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(540, 0X130) << 16);
    // 0x80800084: lwc1        $f16, 0x130($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(540, 0X130));
    // 0x80800088: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8080008C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80800090: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800094: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800098: jal         0x800EFA20
    // 0x8080009C: nop

    func_800EFA20(rdram, ctx);
        goto after_6;
    // 0x8080009C: nop

    after_6:
    // 0x808000A0: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808000A4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808000A8: jal         0x800EE780
    // 0x808000AC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800EE780(rdram, ctx);
        goto after_7;
    // 0x808000AC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_7:
    // 0x808000B0: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x808000B4: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808000B8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808000BC: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x808000C0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808000C4: jal         0x800FAB50
    // 0x808000C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800FAB50(rdram, ctx);
        goto after_8;
    // 0x808000C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x808000CC: beq         $v0, $zero, L_80800100
    if (ctx->r2 == 0) {
        // 0x808000D0: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_80800100;
    }
    // 0x808000D0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808000D4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808000D8: jal         0x800EFB24
    // 0x808000DC: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    func_800EFB24(rdram, ctx);
        goto after_9;
    // 0x808000DC: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    after_9:
    // 0x808000E0: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x808000E4: jal         0x800EF04C
    // 0x808000E8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_10;
    // 0x808000E8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_10:
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: jal         0x8009C0F8
    // 0x808000F4: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_8009C0F8(rdram, ctx);
        goto after_11;
    // 0x808000F4: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_11:
    // 0x808000F8: jal         0x8009C21C
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C21C(rdram, ctx);
        goto after_12;
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_80800100:
    // 0x80800100: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800104: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800108: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

;}
RECOMP_FUNC void func_80800858_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800858: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080085C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800860: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800864: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800868: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080086C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800870: jal         0x80100094
    // 0x80800874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800878: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080087C: jal         0x808007F0
    // 0x80800880: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808007F0_chhandcart(rdram, ctx);
        goto after_1;
    // 0x80800880: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800884: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800888: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080088C: bnel        $t6, $zero, L_8080089C
    if (ctx->r14 != 0) {
        // 0x80800890: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_8080089C;
    }
    goto skip_0;
    // 0x80800890: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800894: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80800898: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_8080089C:
    // 0x8080089C: lbu         $t8, 0x8F4($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X8F4);
    // 0x808008A0: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x808008A4: beq         $at, $zero, L_808008FC
    if (ctx->r1 == 0) {
        // 0x808008A8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808008FC;
    }
    // 0x808008A8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808008AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X43D8) << 16);
    // 0x808008B0: addu        $at, $at, $t8
    gpr jr_addend_808008B8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808008B4: lw          $t8, 0x43D8($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1632, 0X43D8));
    // 0x808008B8: jr          $t8
    // 0x808008BC: nop

    switch (jr_addend_808008B8 >> 2) {
        case 0: goto L_808008C0; break;
        case 1: goto L_808008C8; break;
        case 2: goto L_808008F0; break;
        case 3: goto L_808008C8; break;
        case 4: goto L_808008C8; break;
        default: switch_error(__func__, 0x808008B8, 0x808043D8);
    }
    // 0x808008BC: nop

L_808008C0:
    // 0x808008C0: jal         0x808007BC
    // 0x808008C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808007BC_chhandcart(rdram, ctx);
        goto after_2;
    // 0x808008C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_808008C8:
    // 0x808008C8: jal         0x800856E0
    // 0x808008CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x808008CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x808008D0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x808008D4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x808008D8: sb          $t9, 0x8F4($t0)
    MEM_B(0X8F4, ctx->r8) = ctx->r25;
    // 0x808008DC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x808008E0: jal         0x800880A8
    // 0x808008E4: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    _gcdialogcamera_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x808008E4: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_4:
    // 0x808008E8: jal         0x800880B8
    // 0x808008EC: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x808008EC: nop

    after_5:
L_808008F0:
    // 0x808008F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808008F4: jal         0x800856D8
    // 0x808008F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _capod_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x808008F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
L_808008FC:
    // 0x808008FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800900: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800904: jr          $ra
    // 0x80800908: nop

    return;
    // 0x80800908: nop

;}
RECOMP_FUNC void bababykaz_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D4: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x808003D8: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x808003DC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808003E0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x808003E4: jr          $ra
    // 0x808003E8: nop

    return;
    // 0x808003E8: nop

;}
RECOMP_FUNC void suspline_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808001DC: jr          $ra
    // 0x808001E0: swc1        $f12, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x808001E0: swc1        $f12, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_800BEB4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEB4C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BEB50: jr          $ra
    // 0x800BEB54: lw          $v0, -0x78A0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X78A0);
    return;
    // 0x800BEB54: lw          $v0, -0x78A0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X78A0);
;}
RECOMP_FUNC void func_800BAA9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BAA9C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BAAA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BAAA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BAAA8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800BAAAC: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800BAAB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800BAAB4: jal         0x800BA7C4
    // 0x800BAAB8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_800BA7C4(rdram, ctx);
        goto after_0;
    // 0x800BAAB8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800BAABC: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BAAC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BAAC4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800BAAC8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800BAACC: jal         0x800BA7FC
    // 0x800BAAD0: nop

    func_800BA7FC(rdram, ctx);
        goto after_1;
    // 0x800BAAD0: nop

    after_1:
    // 0x800BAAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BAAD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BAADC: jr          $ra
    // 0x800BAAE0: nop

    return;
    // 0x800BAAE0: nop

;}
RECOMP_FUNC void chmole_training_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808006E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808006E8: jal         0x80106790
    // 0x808006EC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808006EC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x808006F0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x808006F4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808006F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808006FC: beq         $a3, $zero, L_808008BC
    if (ctx->r7 == 0) {
        // 0x80800700: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808008BC;
    }
    // 0x80800700: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800704: beq         $a3, $at, L_808008CC
    if (ctx->r7 == ctx->r1) {
        // 0x80800708: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808008CC;
    }
    // 0x80800708: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080070C: bne         $a3, $at, L_808008D4
    if (ctx->r7 != ctx->r1) {
        // 0x80800710: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_808008D4;
    }
    // 0x80800710: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800714: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80800718: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8080071C: lwc1        $f4, 0x54($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X54);
    // 0x80800720: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800724: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80800728: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8080072C: nop

    // 0x80800730: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800734: beql        $t7, $zero, L_80800784
    if (ctx->r15 == 0) {
        // 0x80800738: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_80800784;
    }
    goto skip_0;
    // 0x80800738: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x8080073C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800740: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800744: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800748: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8080074C: nop

    // 0x80800750: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800754: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800758: nop

    // 0x8080075C: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800760: bne         $t7, $zero, L_80800778
    if (ctx->r15 != 0) {
        // 0x80800764: nop
    
            goto L_80800778;
    }
    // 0x80800764: nop

    // 0x80800768: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8080076C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800770: b           L_80800790
    // 0x80800774: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80800790;
    // 0x80800774: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80800778:
    // 0x80800778: b           L_80800790
    // 0x8080077C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80800790;
    // 0x8080077C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800780: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_80800784:
    // 0x80800784: nop

    // 0x80800788: bltz        $t7, L_80800778
    if (SIGNED(ctx->r15) < 0) {
        // 0x8080078C: nop
    
            goto L_80800778;
    }
    // 0x8080078C: nop

L_80800790:
    // 0x80800790: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80800794: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x80800798: beq         $at, $zero, L_808008AC
    if (ctx->r1 == 0) {
        // 0x8080079C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808008AC;
    }
    // 0x8080079C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808007A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1604, 0XD54) << 16);
    // 0x808007A4: addu        $at, $at, $t7
    gpr jr_addend_808007AC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808007A8: lw          $t7, 0xD54($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1604, 0XD54));
    // 0x808007AC: jr          $t7
    // 0x808007B0: nop

    switch (jr_addend_808007AC >> 2) {
        case 0: goto L_80800820; break;
        case 1: goto L_808007B4; break;
        case 2: goto L_808007D8; break;
        case 3: goto L_80800844; break;
        case 4: goto L_808007FC; break;
        case 5: goto L_8080088C; break;
        case 6: goto L_808008AC; break;
        case 7: goto L_80800868; break;
        default: switch_error(__func__, 0x808007AC, 0x80800D54);
    }
    // 0x808007B0: nop

L_808007B4:
    // 0x808007B4: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x808007B8: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1604, 0XF08) << 16);
    // 0x808007BC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x808007C0: lh          $t9, 0xF08($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(1604, 0XF08));
    // 0x808007C4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x808007C8: nop

    // 0x808007CC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808007D0: b           L_808008AC
    // 0x808007D4: swc1        $f10, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f10.u32l;
        goto L_808008AC;
    // 0x808007D4: swc1        $f10, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f10.u32l;
L_808007D8:
    // 0x808007D8: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x808007DC: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1604, 0XF10) << 16);
    // 0x808007E0: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x808007E4: lh          $t1, 0xF10($t1)
    ctx->r9 = MEM_H(ctx->r9, (int16_t)RELOC_LO16(1604, 0XF10));
    // 0x808007E8: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x808007EC: nop

    // 0x808007F0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808007F4: b           L_808008AC
    // 0x808007F8: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
        goto L_808008AC;
    // 0x808007F8: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
L_808007FC:
    // 0x808007FC: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x80800800: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1604, 0XF18) << 16);
    // 0x80800804: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80800808: lh          $t3, 0xF18($t3)
    ctx->r11 = MEM_H(ctx->r11, (int16_t)RELOC_LO16(1604, 0XF18));
    // 0x8080080C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80800810: nop

    // 0x80800814: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800818: b           L_808008AC
    // 0x8080081C: swc1        $f6, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f6.u32l;
        goto L_808008AC;
    // 0x8080081C: swc1        $f6, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f6.u32l;
L_80800820:
    // 0x80800820: sll         $t4, $a2, 1
    ctx->r12 = S32(ctx->r6 << 1);
    // 0x80800824: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(1604, 0XF20) << 16);
    // 0x80800828: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8080082C: lh          $t5, 0xF20($t5)
    ctx->r13 = MEM_H(ctx->r13, (int16_t)RELOC_LO16(1604, 0XF20));
    // 0x80800830: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80800834: nop

    // 0x80800838: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080083C: b           L_808008AC
    // 0x80800840: swc1        $f10, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f10.u32l;
        goto L_808008AC;
    // 0x80800840: swc1        $f10, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f10.u32l;
L_80800844:
    // 0x80800844: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x80800848: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1604, 0XF24) << 16);
    // 0x8080084C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80800850: lh          $t7, 0xF24($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(1604, 0XF24));
    // 0x80800854: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80800858: nop

    // 0x8080085C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800860: b           L_808008AC
    // 0x80800864: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
        goto L_808008AC;
    // 0x80800864: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
L_80800868:
    // 0x80800868: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8080086C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1604, 0XF28) << 16);
    // 0x80800870: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80800874: lh          $t9, 0xF28($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(1604, 0XF28));
    // 0x80800878: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8080087C: nop

    // 0x80800880: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800884: b           L_808008AC
    // 0x80800888: swc1        $f6, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f6.u32l;
        goto L_808008AC;
    // 0x80800888: swc1        $f6, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f6.u32l;
L_8080088C:
    // 0x8080088C: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x80800890: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1604, 0XF2C) << 16);
    // 0x80800894: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80800898: lh          $t1, 0xF2C($t1)
    ctx->r9 = MEM_H(ctx->r9, (int16_t)RELOC_LO16(1604, 0XF2C));
    // 0x8080089C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x808008A0: nop

    // 0x808008A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808008A8: swc1        $f10, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f10.u32l;
L_808008AC:
    // 0x808008AC: jal         0x80101FDC
    // 0x808008B0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x808008B0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x808008B4: b           L_808008D8
    // 0x808008B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008D8;
    // 0x808008B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008BC:
    // 0x808008BC: jal         0x808004D0
    // 0x808008C0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_808004D0_chmole_training(rdram, ctx);
        goto after_2;
    // 0x808008C0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808008C4: b           L_808008D8
    // 0x808008C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808008D8;
    // 0x808008C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008CC:
    // 0x808008CC: jal         0x80101FDC
    // 0x808008D0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x808008D0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
L_808008D4:
    // 0x808008D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008D8:
    // 0x808008D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008DC: jr          $ra
    // 0x808008E0: nop

    return;
    // 0x808008E0: nop

;}
RECOMP_FUNC void func_80801840_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801840: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801848: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080184C: jal         0x80100094
    // 0x80801850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801854: jal         0x8008A030
    // 0x80801858: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80801858: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080185C: bne         $v0, $zero, L_8080186C
    if (ctx->r2 != 0) {
        // 0x80801860: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080186C;
    }
    // 0x80801860: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801864: b           L_808018CC
    // 0x80801868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808018CC;
    // 0x80801868: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080186C:
    // 0x8080186C: jal         0x80100094
    // 0x80801870: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80801870: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80801874: jal         0x8008A040
    // 0x80801878: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80801878: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8080187C: lbu         $t6, 0x64($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X64);
    // 0x80801880: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80801884: bnel        $t7, $zero, L_808018CC
    if (ctx->r15 != 0) {
        // 0x80801888: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808018CC;
    }
    goto skip_0;
    // 0x80801888: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080188C: lbu         $t8, 0x64($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X64);
    // 0x80801890: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801894: andi        $t9, $t8, 0xFFDF
    ctx->r25 = ctx->r24 & 0XFFDF;
    // 0x80801898: sb          $t9, 0x64($v0)
    MEM_B(0X64, ctx->r2) = ctx->r25;
    // 0x8080189C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808018A0: jal         0x80100094
    // 0x808018A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x808018A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808018A8: jal         0x8008A020
    // 0x808018AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808018AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808018B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808018B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808018B8: jal         0x8010108C
    // 0x808018BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_6;
    // 0x808018BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x808018C0: b           L_808018CC
    // 0x808018C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808018CC;
    // 0x808018C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808018C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808018CC:
    // 0x808018CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808018D4: jr          $ra
    // 0x808018D8: nop

    return;
    // 0x808018D8: nop

;}
RECOMP_FUNC void func_800B2714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2714: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x800B2718: jr          $ra
    // 0x800B271C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    return;
    // 0x800B271C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
;}
RECOMP_FUNC void func_808038AC_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808038AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808038B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808038B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808038B8: jal         0x800D8FF8
    // 0x808038BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808038BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808038C0: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x808038C4: jal         0x80106790
    // 0x808038C8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808038C8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x808038CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808038D0: jal         0x80100094
    // 0x808038D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808038D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808038D8: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x808038DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808038E0: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808038E4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808038E8: lui         $at, 0x439B
    ctx->r1 = S32(0X439B << 16);
    // 0x808038EC: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x808038F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808038F4: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808038F8: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x808038FC: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80803900: nop

    // 0x80803904: bc1fl       L_80803920
    if (!c1cs) {
        // 0x80803908: lbu         $t9, 0x65($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X65);
            goto L_80803920;
    }
    goto skip_0;
    // 0x80803908: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x8080390C: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80803910: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80803914: b           L_80803928
    // 0x80803918: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
        goto L_80803928;
    // 0x80803918: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x8080391C: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
L_80803920:
    // 0x80803920: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x80803924: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_80803928:
    // 0x80803928: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8080392C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80803930: sub.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x80803934: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x80803938: nop

    // 0x8080393C: bc1fl       L_80803958
    if (!c1cs) {
        // 0x80803940: lbu         $t5, 0x65($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X65);
            goto L_80803958;
    }
    goto skip_1;
    // 0x80803940: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    skip_1:
    // 0x80803944: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80803948: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x8080394C: b           L_80803960
    // 0x80803950: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
        goto L_80803960;
    // 0x80803950: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x80803954: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
L_80803958:
    // 0x80803958: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x8080395C: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
L_80803960:
    // 0x80803960: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x80803964: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80803968: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8080396C: sltiu       $at, $t9, 0x9
    ctx->r1 = ctx->r25 < 0X9 ? 1 : 0;
    // 0x80803970: beq         $at, $zero, L_80803DB0
    if (ctx->r1 == 0) {
        // 0x80803974: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80803DB0;
    }
    // 0x80803974: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80803978: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5320) << 16);
    // 0x8080397C: addu        $at, $at, $t9
    gpr jr_addend_80803984 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80803980: lw          $t9, 0x5320($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5320));
    // 0x80803984: jr          $t9
    // 0x80803988: nop

    switch (jr_addend_80803984 >> 2) {
        case 0: goto L_8080398C; break;
        case 1: goto L_808039DC; break;
        case 2: goto L_80803A78; break;
        case 3: goto L_80803A98; break;
        case 4: goto L_80803AE0; break;
        case 5: goto L_80803B6C; break;
        case 6: goto L_80803B6C; break;
        case 7: goto L_80803BC8; break;
        case 8: goto L_80803CC0; break;
        default: switch_error(__func__, 0x80803984, 0x80805320);
    }
    // 0x80803988: nop

L_8080398C:
    // 0x8080398C: lhu         $t1, 0x76($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X76);
    // 0x80803990: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803994: srl         $t2, $t1, 7
    ctx->r10 = S32(U32(ctx->r9) >> 7);
    // 0x80803998: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8080399C: lbu         $v1, 0x0($t3)
    ctx->r3 = MEM_BU(ctx->r11, 0X0);
    // 0x808039A0: beql        $v1, $zero, L_80803DB4
    if (ctx->r3 == 0) {
        // 0x808039A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803DB4;
    }
    goto skip_2;
    // 0x808039A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808039A8: beq         $v1, $at, L_808039CC
    if (ctx->r3 == ctx->r1) {
        // 0x808039AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808039CC;
    }
    // 0x808039AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808039B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808039B4: bne         $v1, $at, L_80803DB0
    if (ctx->r3 != ctx->r1) {
        // 0x808039B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803DB0;
    }
    // 0x808039B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808039BC: jal         0x808036EC
    // 0x808039C0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808036EC_chdragonbrothers(rdram, ctx);
        goto after_3;
    // 0x808039C0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
    // 0x808039C4: b           L_80803DB4
    // 0x808039C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803DB4;
    // 0x808039C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808039CC:
    // 0x808039CC: jal         0x808036EC
    // 0x808039D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808036EC_chdragonbrothers(rdram, ctx);
        goto after_4;
    // 0x808039D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808039D4: b           L_80803DB4
    // 0x808039D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803DB4;
    // 0x808039D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808039DC:
    // 0x808039DC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808039E0: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x808039E4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1852, 0X53A0) << 16);
    // 0x808039E8: addiu       $a3, $a3, 0x53A0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1852, 0X53A0));
    // 0x808039EC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808039F0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808039F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808039F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808039FC: bc1f        L_80803A68
    if (!c1cs) {
        // 0x80803A00: nop
    
            goto L_80803A68;
    }
    // 0x80803A00: nop

    // 0x80803A04: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803A08: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80803A0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80803A10: mul.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80803A14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803A18: sub.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80803A1C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80803A20: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80803A24: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80803A28: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80803A2C: nop

    // 0x80803A30: bc1f        L_80803A58
    if (!c1cs) {
        // 0x80803A34: nop
    
            goto L_80803A58;
    }
    // 0x80803A34: nop

    // 0x80803A38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803A3C: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80803A40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80803A44: nop

    // 0x80803A48: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80803A4C: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80803A50: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80803A54: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_80803A58:
    // 0x80803A58: jal         0x80089D50
    // 0x80803A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80803A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80803A60: b           L_80803DB4
    // 0x80803A64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803DB4;
    // 0x80803A64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803A68:
    // 0x80803A68: jal         0x808036EC
    // 0x80803A6C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808036EC_chdragonbrothers(rdram, ctx);
        goto after_6;
    // 0x80803A6C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80803A70: b           L_80803DB4
    // 0x80803A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803DB4;
    // 0x80803A74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803A78:
    // 0x80803A78: jal         0x80101DDC
    // 0x80803A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_7;
    // 0x80803A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80803A80: beq         $v0, $zero, L_80803DB0
    if (ctx->r2 == 0) {
        // 0x80803A84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803DB0;
    }
    // 0x80803A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803A88: jal         0x808036EC
    // 0x80803A8C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808036EC_chdragonbrothers(rdram, ctx);
        goto after_8;
    // 0x80803A8C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x80803A90: b           L_80803DB4
    // 0x80803A94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803DB4;
    // 0x80803A94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803A98:
    // 0x80803A98: lhu         $t4, 0x76($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X76);
    // 0x80803A9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803AA4: srl         $t5, $t4, 7
    ctx->r13 = S32(U32(ctx->r12) >> 7);
    // 0x80803AA8: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80803AAC: lbu         $v1, 0x0($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X0);
    // 0x80803AB0: beq         $v1, $zero, L_80803AD0
    if (ctx->r3 == 0) {
        // 0x80803AB4: nop
    
            goto L_80803AD0;
    }
    // 0x80803AB4: nop

    // 0x80803AB8: bne         $v1, $at, L_80803DB0
    if (ctx->r3 != ctx->r1) {
        // 0x80803ABC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803DB0;
    }
    // 0x80803ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803AC0: jal         0x808036EC
    // 0x80803AC4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808036EC_chdragonbrothers(rdram, ctx);
        goto after_9;
    // 0x80803AC4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_9:
    // 0x80803AC8: b           L_80803DB4
    // 0x80803ACC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803DB4;
    // 0x80803ACC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803AD0:
    // 0x80803AD0: jal         0x808036EC
    // 0x80803AD4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808036EC_chdragonbrothers(rdram, ctx);
        goto after_10;
    // 0x80803AD4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_10:
    // 0x80803AD8: b           L_80803DB4
    // 0x80803ADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803DB4;
    // 0x80803ADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803AE0:
    // 0x80803AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803AE4: jal         0x80101E14
    // 0x80803AE8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101E14(rdram, ctx);
        goto after_11;
    // 0x80803AE8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_11:
    // 0x80803AEC: beq         $v0, $zero, L_80803B18
    if (ctx->r2 == 0) {
        // 0x80803AF0: nop
    
            goto L_80803B18;
    }
    // 0x80803AF0: nop

    // 0x80803AF4: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    // 0x80803AF8: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x80803AFC: bgez        $t9, L_80803B18
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80803B00: nop
    
            goto L_80803B18;
    }
    // 0x80803B00: nop

    // 0x80803B04: lbu         $a1, 0x79($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X79);
    // 0x80803B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803B0C: srl         $t1, $a1, 4
    ctx->r9 = S32(U32(ctx->r5) >> 4);
    // 0x80803B10: jal         0x80108B04
    // 0x80803B14: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_80108B04(rdram, ctx);
        goto after_12;
    // 0x80803B14: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_12:
L_80803B18:
    // 0x80803B18: jal         0x80101DDC
    // 0x80803B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_13;
    // 0x80803B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80803B20: beql        $v0, $zero, L_80803DB4
    if (ctx->r2 == 0) {
        // 0x80803B24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80803DB4;
    }
    goto skip_3;
    // 0x80803B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80803B28: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80803B2C: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80803B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803B34: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x80803B38: nop

    // 0x80803B3C: bc1f        L_80803B5C
    if (!c1cs) {
        // 0x80803B40: nop
    
            goto L_80803B5C;
    }
    // 0x80803B40: nop

    // 0x80803B44: jal         0x800D8FF8
    // 0x80803B48: nop

    func_800D8FF8(rdram, ctx);
        goto after_14;
    // 0x80803B48: nop

    after_14:
    // 0x80803B4C: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80803B50: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80803B54: b           L_80803DB0
    // 0x80803B58: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
        goto L_80803DB0;
    // 0x80803B58: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80803B5C:
    // 0x80803B5C: jal         0x808036EC
    // 0x80803B60: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808036EC_chdragonbrothers(rdram, ctx);
        goto after_15;
    // 0x80803B60: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_15:
    // 0x80803B64: b           L_80803DB4
    // 0x80803B68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803DB4;
    // 0x80803B68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803B6C:
    // 0x80803B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803B70: jal         0x80101DDC
    // 0x80803B74: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    func_80101DDC(rdram, ctx);
        goto after_16;
    // 0x80803B74: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_16:
    // 0x80803B78: beq         $v0, $zero, L_80803DB0
    if (ctx->r2 == 0) {
        // 0x80803B7C: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_80803DB0;
    }
    // 0x80803B7C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80803B80: lhu         $t2, 0x76($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X76);
    // 0x80803B84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803B8C: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x80803B90: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x80803B94: lbu         $v1, 0x0($t4)
    ctx->r3 = MEM_BU(ctx->r12, 0X0);
    // 0x80803B98: beq         $v1, $zero, L_80803BB8
    if (ctx->r3 == 0) {
        // 0x80803B9C: nop
    
            goto L_80803BB8;
    }
    // 0x80803B9C: nop

    // 0x80803BA0: bne         $v1, $at, L_80803DB0
    if (ctx->r3 != ctx->r1) {
        // 0x80803BA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803DB0;
    }
    // 0x80803BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803BA8: jal         0x808036EC
    // 0x80803BAC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808036EC_chdragonbrothers(rdram, ctx);
        goto after_17;
    // 0x80803BAC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_17:
    // 0x80803BB0: b           L_80803DB4
    // 0x80803BB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803DB4;
    // 0x80803BB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803BB8:
    // 0x80803BB8: jal         0x808036EC
    // 0x80803BBC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808036EC_chdragonbrothers(rdram, ctx);
        goto after_18;
    // 0x80803BBC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_18:
    // 0x80803BC0: b           L_80803DB4
    // 0x80803BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803DB4;
    // 0x80803BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803BC8:
    // 0x80803BC8: lwc1        $f2, 0x1C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80803BCC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80803BD0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1852, 0X53A0) << 16);
    // 0x80803BD4: sub.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80803BD8: addiu       $a3, $a3, 0x53A0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1852, 0X53A0));
    // 0x80803BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803BE0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80803BE4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80803BE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80803BEC: bc1fl       L_80803C7C
    if (!c1cs) {
        // 0x80803BF0: lhu         $t5, 0x76($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X76);
            goto L_80803C7C;
    }
    goto skip_4;
    // 0x80803BF0: lhu         $t5, 0x76($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X76);
    skip_4:
    // 0x80803BF4: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803BF8: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80803BFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803C00: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80803C04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803C08: sub.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80803C0C: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80803C10: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80803C14: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80803C18: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80803C1C: nop

    // 0x80803C20: bc1fl       L_80803C5C
    if (!c1cs) {
        // 0x80803C24: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_80803C5C;
    }
    goto skip_5;
    // 0x80803C24: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_5:
    // 0x80803C28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80803C2C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80803C30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803C34: lui         $at, 0x439B
    ctx->r1 = S32(0X439B << 16);
    // 0x80803C38: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80803C3C: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80803C40: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80803C44: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80803C48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80803C4C: mul.s       $f10, $f12, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x80803C50: sub.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80803C54: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x80803C58: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_80803C5C:
    // 0x80803C5C: nop

    // 0x80803C60: bc1f        L_80803C6C
    if (!c1cs) {
        // 0x80803C64: nop
    
            goto L_80803C6C;
    }
    // 0x80803C64: nop

    // 0x80803C68: swc1        $f14, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f14.u32l;
L_80803C6C:
    // 0x80803C6C: jal         0x80089D50
    // 0x80803C70: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_19;
    // 0x80803C70: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_19:
    // 0x80803C74: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80803C78: lhu         $t5, 0x76($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X76);
L_80803C7C:
    // 0x80803C7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803C84: srl         $t6, $t5, 7
    ctx->r14 = S32(U32(ctx->r13) >> 7);
    // 0x80803C88: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x80803C8C: lbu         $v1, 0x0($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X0);
    // 0x80803C90: beq         $v1, $at, L_80803CB0
    if (ctx->r3 == ctx->r1) {
        // 0x80803C94: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80803CB0;
    }
    // 0x80803C94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803C98: bne         $v1, $at, L_80803DB0
    if (ctx->r3 != ctx->r1) {
        // 0x80803C9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803DB0;
    }
    // 0x80803C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803CA0: jal         0x808036EC
    // 0x80803CA4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808036EC_chdragonbrothers(rdram, ctx);
        goto after_20;
    // 0x80803CA4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_20:
    // 0x80803CA8: b           L_80803DB4
    // 0x80803CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803DB4;
    // 0x80803CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803CB0:
    // 0x80803CB0: jal         0x808036EC
    // 0x80803CB4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808036EC_chdragonbrothers(rdram, ctx);
        goto after_21;
    // 0x80803CB4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_21:
    // 0x80803CB8: b           L_80803DB4
    // 0x80803CBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803DB4;
    // 0x80803CBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803CC0:
    // 0x80803CC0: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80803CC4: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80803CC8: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1852, 0X53A0) << 16);
    // 0x80803CCC: sub.s       $f2, $f8, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x80803CD0: addiu       $a3, $a3, 0x53A0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1852, 0X53A0));
    // 0x80803CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803CD8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80803CDC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80803CE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80803CE4: bc1fl       L_80803D74
    if (!c1cs) {
        // 0x80803CE8: lhu         $t8, 0x76($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X76);
            goto L_80803D74;
    }
    goto skip_6;
    // 0x80803CE8: lhu         $t8, 0x76($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X76);
    skip_6:
    // 0x80803CEC: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803CF0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80803CF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803CF8: mul.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80803CFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80803D00: sub.s       $f18, $f2, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80803D04: sub.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80803D08: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80803D0C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80803D10: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80803D14: nop

    // 0x80803D18: bc1fl       L_80803D54
    if (!c1cs) {
        // 0x80803D1C: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80803D54;
    }
    goto skip_7;
    // 0x80803D1C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_7:
    // 0x80803D20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80803D24: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80803D28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803D2C: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80803D30: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80803D34: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80803D38: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80803D3C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80803D40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80803D44: mul.s       $f18, $f12, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80803D48: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80803D4C: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x80803D50: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80803D54:
    // 0x80803D54: nop

    // 0x80803D58: bc1f        L_80803D64
    if (!c1cs) {
        // 0x80803D5C: nop
    
            goto L_80803D64;
    }
    // 0x80803D5C: nop

    // 0x80803D60: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
L_80803D64:
    // 0x80803D64: jal         0x80089D50
    // 0x80803D68: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_22;
    // 0x80803D68: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_22:
    // 0x80803D6C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80803D70: lhu         $t8, 0x76($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X76);
L_80803D74:
    // 0x80803D74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803D7C: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x80803D80: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x80803D84: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x80803D88: beq         $v1, $zero, L_80803DA8
    if (ctx->r3 == 0) {
        // 0x80803D8C: nop
    
            goto L_80803DA8;
    }
    // 0x80803D8C: nop

    // 0x80803D90: bne         $v1, $at, L_80803DB0
    if (ctx->r3 != ctx->r1) {
        // 0x80803D94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803DB0;
    }
    // 0x80803D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803D98: jal         0x808036EC
    // 0x80803D9C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808036EC_chdragonbrothers(rdram, ctx);
        goto after_23;
    // 0x80803D9C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_23:
    // 0x80803DA0: b           L_80803DB4
    // 0x80803DA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803DB4;
    // 0x80803DA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803DA8:
    // 0x80803DA8: jal         0x808036EC
    // 0x80803DAC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808036EC_chdragonbrothers(rdram, ctx);
        goto after_24;
    // 0x80803DAC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_24:
L_80803DB0:
    // 0x80803DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803DB4:
    // 0x80803DB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803DB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80803DBC: jr          $ra
    // 0x80803DC0: nop

    return;
    // 0x80803DC0: nop

;}
RECOMP_FUNC void func_800E3D0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3D0C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800E3D10: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800E3D14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3D18: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800E3D1C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3D20: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    // 0x800E3D24: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800E3D28: jal         0x800CAA24
    // 0x800E3D2C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_800CAA24(rdram, ctx);
        goto after_0;
    // 0x800E3D2C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x800E3D30: jal         0x800BCC58
    // 0x800E3D34: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    func_800BCC58(rdram, ctx);
        goto after_1;
    // 0x800E3D34: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800E3D38: beq         $v0, $zero, L_800E3DAC
    if (ctx->r2 == 0) {
        // 0x800E3D3C: lw          $v1, 0x4C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X4C);
            goto L_800E3DAC;
    }
    // 0x800E3D3C: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x800E3D40: bne         $v1, $zero, L_800E3DAC
    if (ctx->r3 != 0) {
        // 0x800E3D44: addiu       $a0, $sp, 0x3C
        ctx->r4 = ADD32(ctx->r29, 0X3C);
            goto L_800E3DAC;
    }
    // 0x800E3D44: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800E3D48: jal         0x800BCC28
    // 0x800E3D4C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_800BCC28(rdram, ctx);
        goto after_2;
    // 0x800E3D4C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x800E3D50: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800E3D54: jal         0x800BCC28
    // 0x800E3D58: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800BCC28(rdram, ctx);
        goto after_3;
    // 0x800E3D58: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_3:
    // 0x800E3D5C: addiu       $v1, $sp, 0x30
    ctx->r3 = ADD32(ctx->r29, 0X30);
    // 0x800E3D60: addiu       $v0, $sp, 0x3C
    ctx->r2 = ADD32(ctx->r29, 0X3C);
    // 0x800E3D64: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
L_800E3D68:
    // 0x800E3D68: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800E3D6C: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800E3D70: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800E3D74: nop

    // 0x800E3D78: bc1fl       L_800E3D8C
    if (!c1cs) {
        // 0x800E3D7C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800E3D8C;
    }
    goto skip_0;
    // 0x800E3D7C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_0:
    // 0x800E3D80: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800E3D84: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x800E3D88: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800E3D8C:
    // 0x800E3D8C: bne         $v0, $a0, L_800E3D68
    if (ctx->r2 != ctx->r4) {
        // 0x800E3D90: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800E3D68;
    }
    // 0x800E3D90: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800E3D94: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3D98: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    // 0x800E3D9C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800E3DA0: jal         0x800CAA24
    // 0x800E3DA4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_800CAA24(rdram, ctx);
        goto after_4;
    // 0x800E3DA4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x800E3DA8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800E3DAC:
    // 0x800E3DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3DB0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800E3DB4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800E3DB8: jr          $ra
    // 0x800E3DBC: nop

    return;
    // 0x800E3DBC: nop

;}
RECOMP_FUNC void func_800CB870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB870: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800CB874: addiu       $v0, $v0, -0x5190
    ctx->r2 = ADD32(ctx->r2, -0X5190);
    // 0x800CB878: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x800CB87C: jr          $ra
    // 0x800CB880: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    return;
    // 0x800CB880: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800CB884: nop

    // 0x800CB888: nop

    // 0x800CB88C: nop

;}
RECOMP_FUNC void inantab_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80806594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806598: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080659C: jal         0x8010114C
    // 0x808065A0: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x808065A0: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_0:
    // 0x808065A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808065A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808065AC: jr          $ra
    // 0x808065B0: nop

    return;
    // 0x808065B0: nop

;}
RECOMP_FUNC void func_800DF8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF8BC: jr          $ra
    // 0x800DF8C0: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    return;
    // 0x800DF8C0: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
;}
RECOMP_FUNC void basetup_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800844: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800848: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080084C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800850: jal         0x800A3274
    // 0x80800854: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x80800854: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800858: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080085C: beql        $v0, $at, L_80800874
    if (ctx->r2 == ctx->r1) {
        // 0x80800860: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800874;
    }
    goto skip_0;
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800864: jal         0x80088240
    // 0x80800868: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _gclevel_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800868: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8080086C: beq         $v0, $zero, L_80800884
    if (ctx->r2 == 0) {
        // 0x80800870: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800884;
    }
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800874:
    // 0x80800874: jal         0x800F44DC
    // 0x80800878: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F44DC(rdram, ctx);
        goto after_2;
    // 0x80800878: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080087C: b           L_80800B10
    // 0x80800880: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B10;
    // 0x80800880: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800884:
    // 0x80800884: jal         0x80800534
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800534_basetup(rdram, ctx);
        goto after_3;
    // 0x80800888: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080088C: bnel        $v0, $zero, L_80800B10
    if (ctx->r2 != 0) {
        // 0x80800890: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800B10;
    }
    goto skip_1;
    // 0x80800890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800894: jal         0x800EA090
    // 0x80800898: nop

    func_800EA090(rdram, ctx);
        goto after_4;
    // 0x80800898: nop

    after_4:
    // 0x8080089C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x808008A0: jal         0x808006F0
    // 0x808008A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808006F0_basetup(rdram, ctx);
        goto after_5;
    // 0x808008A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x808008A8: beq         $v0, $zero, L_808008C0
    if (ctx->r2 == 0) {
        // 0x808008AC: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_808008C0;
    }
    // 0x808008AC: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x808008B0: jal         0x8080071C
    // 0x808008B4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    func_8080071C_basetup(rdram, ctx);
        goto after_6;
    // 0x808008B4: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_6:
    // 0x808008B8: b           L_80800900
    // 0x808008BC: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
        goto L_80800900;
    // 0x808008BC: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
L_808008C0:
    // 0x808008C0: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x808008C4: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x808008C8: jal         0x8008A370
    // 0x808008CC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    _sudeathmatch_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x808008CC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_7:
    // 0x808008D0: beq         $v0, $zero, L_808008E4
    if (ctx->r2 == 0) {
        // 0x808008D4: lw          $t6, 0x64($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X64);
            goto L_808008E4;
    }
    // 0x808008D4: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x808008D8: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808008DC: b           L_808008FC
    // 0x808008E0: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
        goto L_808008FC;
    // 0x808008E0: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
L_808008E4:
    // 0x808008E4: bne         $t6, $zero, L_808008FC
    if (ctx->r14 != 0) {
        // 0x808008E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008FC;
    }
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008EC: jal         0x800F44DC
    // 0x808008F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F44DC(rdram, ctx);
        goto after_8;
    // 0x808008F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808008F4: b           L_80800B10
    // 0x808008F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B10;
    // 0x808008F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008FC:
    // 0x808008FC: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
L_80800900:
    // 0x80800900: jal         0x80800778
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800778_basetup(rdram, ctx);
        goto after_9;
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800908: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8080090C: bne         $v0, $at, L_80800980
    if (ctx->r2 != ctx->r1) {
        // 0x80800910: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_80800980;
    }
    // 0x80800910: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800918: jal         0x80085008
    // 0x8080091C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bashoes_entrypoint_6(rdram, ctx);
        goto after_10;
    // 0x8080091C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800920: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800924: jal         0x8009EB0C
    // 0x80800928: nop

    func_8009EB0C(rdram, ctx);
        goto after_11;
    // 0x80800928: nop

    after_11:
    // 0x8080092C: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80800930: beq         $t7, $zero, L_80800958
    if (ctx->r15 == 0) {
        // 0x80800934: nop
    
            goto L_80800958;
    }
    // 0x80800934: nop

    // 0x80800938: jal         0x8009E994
    // 0x8080093C: nop

    func_8009E994(rdram, ctx);
        goto after_12;
    // 0x8080093C: nop

    after_12:
    // 0x80800940: bne         $v0, $zero, L_80800958
    if (ctx->r2 != 0) {
        // 0x80800944: nop
    
            goto L_80800958;
    }
    // 0x80800944: nop

    // 0x80800948: jal         0x8009E958
    // 0x8080094C: nop

    func_8009E958(rdram, ctx);
        goto after_13;
    // 0x8080094C: nop

    after_13:
    // 0x80800950: b           L_80800980
    // 0x80800954: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
        goto L_80800980;
    // 0x80800954: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_80800958:
    // 0x80800958: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8080095C: lbu         $t8, 0x762C($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X762C);
    // 0x80800960: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80800964: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800968: bne         $t8, $at, L_80800978
    if (ctx->r24 != ctx->r1) {
        // 0x8080096C: nop
    
            goto L_80800978;
    }
    // 0x8080096C: nop

    // 0x80800970: b           L_80800978
    // 0x80800974: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800978;
    // 0x80800974: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800978:
    // 0x80800978: jal         0x800A3544
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3544(rdram, ctx);
        goto after_14;
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_80800980:
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800984: jal         0x800A3410
    // 0x80800988: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800A3410(rdram, ctx);
        goto after_15;
    // 0x80800988: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_15:
    // 0x8080098C: jal         0x80092778
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092778(rdram, ctx);
        goto after_16;
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800998: jal         0x800F44DC
    // 0x8080099C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F44DC(rdram, ctx);
        goto after_17;
    // 0x8080099C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x808009A0: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x808009A4: beql        $a0, $zero, L_808009D0
    if (ctx->r4 == 0) {
        // 0x808009A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009D0;
    }
    goto skip_2;
    // 0x808009A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808009AC: jal         0x80088C00
    // 0x808009B0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_18;
    // 0x808009B0: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_18:
    // 0x808009B4: jal         0x80088C08
    // 0x808009B8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    _gspropctrl_entrypoint_12(rdram, ctx);
        goto after_19;
    // 0x808009B8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_19:
    // 0x808009BC: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x808009C0: nop

    // 0x808009C4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808009C8: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808009D0:
    // 0x808009D0: jal         0x800F44DC
    // 0x808009D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F44DC(rdram, ctx);
        goto after_20;
    // 0x808009D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x808009D8: lw          $t0, 0x100($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X100);
    // 0x808009DC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x808009E0: jal         0x8009EA4C
    // 0x808009E4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    func_8009EA4C(rdram, ctx);
        goto after_21;
    // 0x808009E4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    after_21:
    // 0x808009E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808009EC: bnel        $v0, $at, L_80800A3C
    if (ctx->r2 != ctx->r1) {
        // 0x808009F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A3C;
    }
    goto skip_3;
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x808009F4: jal         0x800EA068
    // 0x808009F8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800EA068(rdram, ctx);
        goto after_22;
    // 0x808009F8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_22:
    // 0x808009FC: beql        $v0, $zero, L_80800A28
    if (ctx->r2 == 0) {
        // 0x80800A00: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80800A28;
    }
    goto skip_4;
    // 0x80800A00: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_4:
    // 0x80800A04: jal         0x800C6E38
    // 0x80800A08: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_800C6E38(rdram, ctx);
        goto after_23;
    // 0x80800A08: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_23:
    // 0x80800A0C: beql        $v0, $zero, L_80800A28
    if (ctx->r2 == 0) {
        // 0x80800A10: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80800A28;
    }
    goto skip_5;
    // 0x80800A10: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_5:
    // 0x80800A14: jal         0x8009EAD0
    // 0x80800A18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8009EAD0(rdram, ctx);
        goto after_24;
    // 0x80800A18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_24:
    // 0x80800A1C: b           L_80800A3C
    // 0x80800A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800A3C;
    // 0x80800A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A24: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80800A28:
    // 0x80800A28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800A2C: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800A30: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800A34: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A3C:
    // 0x80800A3C: jal         0x8009C914
    // 0x80800A40: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    yaw_setIdeal(rdram, ctx);
        goto after_25;
    // 0x80800A40: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_25:
    // 0x80800A44: jal         0x8009C974
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_26;
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800A4C: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x80800A50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A58: beq         $t1, $zero, L_80800AFC
    if (ctx->r9 == 0) {
        // 0x80800A5C: nop
    
            goto L_80800AFC;
    }
    // 0x80800A5C: nop

    // 0x80800A60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A64: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800A68: jal         0x800EA068
    // 0x80800A6C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_800EA068(rdram, ctx);
        goto after_27;
    // 0x80800A6C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_27:
    // 0x80800A70: beql        $v0, $zero, L_80800A9C
    if (ctx->r2 == 0) {
        // 0x80800A74: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80800A9C;
    }
    goto skip_6;
    // 0x80800A74: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    skip_6:
    // 0x80800A78: jal         0x80088C10
    // 0x80800A7C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    _gspropctrl_entrypoint_13(rdram, ctx);
        goto after_28;
    // 0x80800A7C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_28:
    // 0x80800A80: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80800A84: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(584, 0XB30) << 16);
    // 0x80800A88: lwc1        $f10, 0xB30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(584, 0XB30));
    // 0x80800A8C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800A90: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800A94: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80800A98: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
L_80800A9C:
    // 0x80800A9C: jal         0x80088C00
    // 0x80800AA0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_29;
    // 0x80800AA0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_29:
    // 0x80800AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800AAC: jal         0x80800194
    // 0x80800AB0: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_80800194_basetup(rdram, ctx);
        goto after_30;
    // 0x80800AB0: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_30:
    // 0x80800AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AB8: jal         0x800F452C
    // 0x80800ABC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F452C(rdram, ctx);
        goto after_31;
    // 0x80800ABC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_31:
    // 0x80800AC0: jal         0x808002D4
    // 0x80800AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002D4_basetup(rdram, ctx);
        goto after_32;
    // 0x80800AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800AC8: jal         0x800F497C
    // 0x80800ACC: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F497C(rdram, ctx);
        goto after_33;
    // 0x80800ACC: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_33:
    // 0x80800AD0: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x80800AD4: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800AD8: addiu       $a1, $a1, 0x4FA8
    ctx->r5 = ADD32(ctx->r5, 0X4FA8);
    // 0x80800ADC: jal         0x800F49D4
    // 0x80800AE0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_800F49D4(rdram, ctx);
        goto after_34;
    // 0x80800AE0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_34:
    // 0x80800AE4: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x80800AE8: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80800AEC: jal         0x800F4A8C
    // 0x80800AF0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_800F4A8C(rdram, ctx);
        goto after_35;
    // 0x80800AF0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_35:
    // 0x80800AF4: b           L_80800B10
    // 0x80800AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B10;
    // 0x80800AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800AFC:
    // 0x80800AFC: jal         0x800F452C
    // 0x80800B00: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800F452C(rdram, ctx);
        goto after_36;
    // 0x80800B00: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_36:
    // 0x80800B04: jal         0x808002D4
    // 0x80800B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002D4_basetup(rdram, ctx);
        goto after_37;
    // 0x80800B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800B0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B10:
    // 0x80800B10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B14: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80800B18: jr          $ra
    // 0x80800B1C: nop

    return;
    // 0x80800B1C: nop

;}
RECOMP_FUNC void func_808002A4_gcdialogcamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002AC: jal         0x80106790
    // 0x808002B0: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808002B0: nop

    after_0:
    // 0x808002B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808002B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808002BC: jal         0x800856F0
    // 0x808002C0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    _capod_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x808002C0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_1:
    // 0x808002C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808002C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808002CC: jal         0x800856F8
    // 0x808002D0: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    _capod_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x808002D0: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    after_2:
    // 0x808002D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002DC: jr          $ra
    // 0x808002E0: nop

    return;
    // 0x808002E0: nop

;}
RECOMP_FUNC void subaddietaxi_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080046C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800470: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800474: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800478: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080047C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800480: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800484: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80800488: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8080048C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80800490: jal         0x800CB45C
    // 0x80800494: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    func_800CB45C(rdram, ctx);
        goto after_0;
    // 0x80800494: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x80800498: jal         0x800EA05C
    // 0x8080049C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_800EA05C(rdram, ctx);
        goto after_1;
    // 0x8080049C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x808004A0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x808004A4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808004A8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808004AC: bne         $v0, $t6, L_80800504
    if (ctx->r2 != ctx->r14) {
        // 0x808004B0: addiu       $a1, $sp, 0x2C
        ctx->r5 = ADD32(ctx->r29, 0X2C);
            goto L_80800504;
    }
    // 0x808004B0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808004B4: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x808004B8: jal         0x800EE7F8
    // 0x808004BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808004BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x808004C0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x808004C4: lhu         $t1, 0x76($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X76);
    // 0x808004C8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808004CC: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x808004D0: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x808004D4: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x808004D8: sh          $t3, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r11;
    // 0x808004DC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x808004E0: jal         0x80089CA0
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808004E8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3334, 0XD5C) << 16);
    // 0x808004EC: addiu       $a2, $a2, 0xD5C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3334, 0XD5C));
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F4: jal         0x80089D18
    // 0x808004F8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808004F8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808004FC: b           L_80800510
    // 0x80800500: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
        goto L_80800510;
    // 0x80800500: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
L_80800504:
    // 0x80800504: jal         0x800FFAB0
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080050C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
L_80800510:
    // 0x80800510: jal         0x800CB698
    // 0x80800514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CB698(rdram, ctx);
        goto after_6;
    // 0x80800514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800518: jal         0x800CB70C
    // 0x8080051C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800CB70C(rdram, ctx);
        goto after_7;
    // 0x8080051C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_7:
    // 0x80800520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800524: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800528: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080052C: jr          $ra
    // 0x80800530: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800530: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800BFCB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFCB4: jr          $ra
    // 0x800BFCB8: nop

    return;
    // 0x800BFCB8: nop

;}
RECOMP_FUNC void func_808023B4_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808023B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808023B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808023BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808023C0: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x808023C4: ori         $t6, $a2, 0x4
    ctx->r14 = ctx->r6 | 0X4;
    // 0x808023C8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x808023CC: addiu       $t8, $zero, 0x36
    ctx->r24 = ADD32(0, 0X36);
    // 0x808023D0: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x808023D4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808023D8: jal         0x8008A208
    // 0x808023DC: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x808023DC: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    after_0:
    // 0x808023E0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x808023E4: lbu         $t0, 0x74($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X74);
    // 0x808023E8: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x808023EC: sb          $t1, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r9;
    // 0x808023F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808023F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808023F8: jr          $ra
    // 0x808023FC: nop

    return;
    // 0x808023FC: nop

;}
RECOMP_FUNC void func_80800520_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800520: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800524: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800528: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080052C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800530: jal         0x80100094
    // 0x80800534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800538: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080053C: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800540: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800544: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800548: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080054C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800550: addiu       $t6, $zero, 0x401
    ctx->r14 = ADD32(0, 0X401);
    // 0x80800554: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800558: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080055C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800560: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080056C: jal         0x80089F90
    // 0x80800570: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800570: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800574: bne         $v0, $zero, L_80800590
    if (ctx->r2 != 0) {
        // 0x80800578: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800590;
    }
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800580: jal         0x80102424
    // 0x80800584: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800584: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80800588: b           L_8080059C
    // 0x8080058C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
        goto L_8080059C;
    // 0x8080058C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_80800590:
    // 0x80800590: jal         0x80102424
    // 0x80800594: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800594: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80800598: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_8080059C:
    // 0x8080059C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808005A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808005A4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808005A8: jal         0x800DC178
    // 0x808005AC: nop

    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808005AC: nop

    after_4:
    // 0x808005B0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808005B4: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x808005B8: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x808005BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808005C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005C8: jr          $ra
    // 0x808005CC: nop

    return;
    // 0x808005CC: nop

;}
RECOMP_FUNC void func_8080230C_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080230C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802314: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802318: addiu       $a1, $a0, 0x18
    ctx->r5 = ADD32(ctx->r4, 0X18);
    // 0x8080231C: jal         0x80102D78
    // 0x80802320: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80102D78(rdram, ctx);
        goto after_0;
    // 0x80802320: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802324: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802328: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8080232C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80802330: jal         0x800F1DCC
    // 0x80802334: lwc1        $f12, 0x48($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x80802334: lwc1        $f12, 0x48($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X48);
    after_1:
    // 0x80802338: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080233C: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80802340: lui         $at, 0xC2DC
    ctx->r1 = S32(0XC2DC << 16);
    // 0x80802344: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80802348: nop

    // 0x8080234C: bc1fl       L_80802368
    if (!c1cs) {
        // 0x80802350: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80802368;
    }
    goto skip_0;
    // 0x80802350: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80802354: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80802358: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080235C: b           L_8080236C
    // 0x80802360: nop

        goto L_8080236C;
    // 0x80802360: nop

    // 0x80802364: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80802368:
    // 0x80802368: nop

L_8080236C:
    // 0x8080236C: jal         0x800136E4
    // 0x80802370: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x80802370: add.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f6.fl;
    after_2:
    // 0x80802374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802378: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080237C: jr          $ra
    // 0x80802380: nop

    return;
    // 0x80802380: nop

;}
RECOMP_FUNC void func_800CB0E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB0E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB0EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CB0F0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800CB0F4: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800CB0F8: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x800CB0FC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800CB100: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800CB104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB108: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800CB10C: jal         0x800EE7F8
    // 0x800CB110: addiu       $a1, $a1, 0x128
    ctx->r5 = ADD32(ctx->r5, 0X128);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800CB110: addiu       $a1, $a1, 0x128
    ctx->r5 = ADD32(ctx->r5, 0X128);
    after_0:
    // 0x800CB114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB11C: jr          $ra
    // 0x800CB120: nop

    return;
    // 0x800CB120: nop

;}
RECOMP_FUNC void chweather_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(732, 0X560) << 16);
    // 0x8080010C: jr          $ra
    // 0x80800110: addiu       $v0, $v0, 0x560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X560));
    return;
    // 0x80800110: addiu       $v0, $v0, 0x560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X560));
;}
RECOMP_FUNC void _glgamedata_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088570: syscall     693
    recomp_syscall_handler(rdram, ctx, 0x80088570);
    return;
    // 0x80088574: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chbadshad_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800490: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800494: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800498: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8080049C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004A0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808004A4: bne         $a3, $zero, L_808004B0
    if (ctx->r7 != 0) {
        // 0x808004A8: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_808004B0;
    }
    // 0x808004A8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808004AC: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
L_808004B0:
    // 0x808004B0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808004B4: jal         0x8008A0D0
    // 0x808004B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808004B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x808004BC: beq         $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808004C0: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808004FC;
    }
    // 0x808004C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808004C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004C8: jal         0x80800464
    // 0x808004CC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    chbadshad_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808004CC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x808004D0: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x808004D4: lw          $a0, 0x40($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X40);
    // 0x808004D8: beq         $a0, $zero, L_808004F4
    if (ctx->r4 == 0) {
        // 0x808004DC: nop
    
            goto L_808004F4;
    }
    // 0x808004DC: nop

    // 0x808004E0: jal         0x80106790
    // 0x808004E4: nop

    func_80106790(rdram, ctx);
        goto after_2;
    // 0x808004E4: nop

    after_2:
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: jal         0x800EE7F8
    // 0x808004F0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808004F0: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_3:
L_808004F4:
    // 0x808004F4: b           L_80800500
    // 0x808004F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800500;
    // 0x808004F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004FC:
    // 0x808004FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800500:
    // 0x80800500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800504: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800508: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080050C: jr          $ra
    // 0x80800510: nop

    return;
    // 0x80800510: nop

;}
RECOMP_FUNC void func_80801164_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801164: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80801168: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080116C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801170: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80801174: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801178: jal         0x80100094
    // 0x8080117C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080117C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801180: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80801184: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80801188: lw          $a2, 0x18($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X18);
    // 0x8080118C: sll         $t7, $a2, 11
    ctx->r15 = S32(ctx->r6 << 11);
    // 0x80801190: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x80801194: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x80801198: bne         $at, $zero, L_808012D8
    if (ctx->r1 != 0) {
        // 0x8080119C: or          $a2, $t8, $zero
        ctx->r6 = ctx->r24 | 0;
            goto L_808012D8;
    }
    // 0x8080119C: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x808011A0: slti        $at, $t8, 0xF
    ctx->r1 = SIGNED(ctx->r24) < 0XF ? 1 : 0;
    // 0x808011A4: beq         $at, $zero, L_808012D8
    if (ctx->r1 == 0) {
        // 0x808011A8: addiu       $v1, $t8, -0x3
        ctx->r3 = ADD32(ctx->r24, -0X3);
            goto L_808012D8;
    }
    // 0x808011A8: addiu       $v1, $t8, -0x3
    ctx->r3 = ADD32(ctx->r24, -0X3);
    // 0x808011AC: addu        $t9, $v0, $v1
    ctx->r25 = ADD32(ctx->r2, ctx->r3);
    // 0x808011B0: lbu         $t0, 0x487($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X487);
    // 0x808011B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808011B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011BC: beq         $t0, $at, L_808012D8
    if (ctx->r8 == ctx->r1) {
        // 0x808011C0: addiu       $a1, $sp, 0x44
        ctx->r5 = ADD32(ctx->r29, 0X44);
            goto L_808012D8;
    }
    // 0x808011C0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x808011C4: jal         0x80802590
    // 0x808011C8: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    func_80802590_chinflatableboss(rdram, ctx);
        goto after_1;
    // 0x808011C8: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    after_1:
    // 0x808011CC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(832, 0X2F08) << 16);
    // 0x808011D0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808011D4: addiu       $a2, $a2, 0x2F08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(832, 0X2F08));
    // 0x808011D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011DC: jal         0x80089D18
    // 0x808011E0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808011E0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_2:
    // 0x808011E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011E8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x808011EC: jal         0x808012EC
    // 0x808011F0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    func_808012EC_chinflatableboss(rdram, ctx);
        goto after_3;
    // 0x808011F0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x808011F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011F8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x808011FC: jal         0x80801904
    // 0x80801200: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_80801904_chinflatableboss(rdram, ctx);
        goto after_4;
    // 0x80801200: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_4:
    // 0x80801204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801208: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8080120C: jal         0x80801FC0
    // 0x80801210: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_80801FC0_chinflatableboss(rdram, ctx);
        goto after_5;
    // 0x80801210: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_5:
    // 0x80801214: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80801218: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8080121C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801220: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80801224: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80801228: sw          $v0, 0x43C($t4)
    MEM_W(0X43C, ctx->r12) = ctx->r2;
    // 0x8080122C: jal         0x80802AD8
    // 0x80801230: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80802AD8_chinflatableboss(rdram, ctx);
        goto after_6;
    // 0x80801230: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_6:
    // 0x80801234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801238: jal         0x80800F84
    // 0x8080123C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800F84_chinflatableboss(rdram, ctx);
        goto after_7;
    // 0x8080123C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_7:
    // 0x80801240: jal         0x80104248
    // 0x80801244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_8;
    // 0x80801244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801248: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x8080124C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801250: jal         0x8008B1C8
    // 0x80801254: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_9;
    // 0x80801254: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x80801258: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8080125C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80801260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801264: jal         0x80801CB4
    // 0x80801268: sb          $t5, 0x493($t6)
    MEM_B(0X493, ctx->r14) = ctx->r13;
    func_80801CB4_chinflatableboss(rdram, ctx);
        goto after_10;
    // 0x80801268: sb          $t5, 0x493($t6)
    MEM_B(0X493, ctx->r14) = ctx->r13;
    after_10:
    // 0x8080126C: beq         $v0, $zero, L_808012C0
    if (ctx->r2 == 0) {
        // 0x80801270: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_808012C0;
    }
    // 0x80801270: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80801274: bnel        $v0, $at, L_808012DC
    if (ctx->r2 != ctx->r1) {
        // 0x80801278: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808012DC;
    }
    goto skip_0;
    // 0x80801278: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080127C: jal         0x800DA544
    // 0x80801280: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800DA544(rdram, ctx);
        goto after_11;
    // 0x80801280: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_11:
    // 0x80801284: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801288: addiu       $t7, $zero, 0x3A
    ctx->r15 = ADD32(0, 0X3A);
    // 0x8080128C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801290: addiu       $a1, $zero, 0x1085
    ctx->r5 = ADD32(0, 0X1085);
    // 0x80801294: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    // 0x80801298: jal         0x8008A208
    // 0x8080129C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_12;
    // 0x8080129C: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_12:
    // 0x808012A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012A4: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x808012A8: jal         0x80802A00
    // 0x808012AC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_80802A00_chinflatableboss(rdram, ctx);
        goto after_13;
    // 0x808012AC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_13:
    // 0x808012B0: lbu         $t9, 0x74($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X74);
    // 0x808012B4: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x808012B8: b           L_808012D8
    // 0x808012BC: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
        goto L_808012D8;
    // 0x808012BC: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
L_808012C0:
    // 0x808012C0: jal         0x800DA544
    // 0x808012C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA544(rdram, ctx);
        goto after_14;
    // 0x808012C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x808012C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012CC: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    // 0x808012D0: jal         0x80802A00
    // 0x808012D4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    func_80802A00_chinflatableboss(rdram, ctx);
        goto after_15;
    // 0x808012D4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_15:
L_808012D8:
    // 0x808012D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808012DC:
    // 0x808012DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808012E0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x808012E4: jr          $ra
    // 0x808012E8: nop

    return;
    // 0x808012E8: nop

;}
RECOMP_FUNC void _bsmummove_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800838A0: syscall     78
    recomp_syscall_handler(rdram, ctx, 0x800838A0);
    return;
    // 0x800838A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chjigsawcollect_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800600: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800604: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800608: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080060C: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x80800610: addiu       $a0, $zero, 0x4EF
    ctx->r4 = ADD32(0, 0X4EF);
    // 0x80800614: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800618: jal         0x80108528
    // 0x8080061C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80108528(rdram, ctx);
        goto after_0;
    // 0x8080061C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x80800620: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800624: lbu         $t9, 0x73($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X73);
    // 0x80800628: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080062C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80800630: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x80800634: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800638: sb          $t1, 0x73($v0)
    MEM_B(0X73, ctx->r2) = ctx->r9;
    // 0x8080063C: jal         0x80100094
    // 0x80800640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800644: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80800648: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x8080064C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800654: jr          $ra
    // 0x80800658: nop

    return;
    // 0x80800658: nop

    // 0x8080065C: nop

;}
RECOMP_FUNC void func_800148B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800148B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800148B4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800148B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800148BC: jr          $ra
    // 0x800148C0: sw          $t6, -0x7B80($at)
    MEM_W(-0X7B80, ctx->r1) = ctx->r14;
    return;
    // 0x800148C0: sw          $t6, -0x7B80($at)
    MEM_W(-0X7B80, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_808002F0_chhillbilly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002F8: jal         0x8008A110
    // 0x808002FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _sucoaster_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808002FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800300: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800304: jal         0x800EE88C
    // 0x80800308: addiu       $a1, $v0, 0x6
    ctx->r5 = ADD32(ctx->r2, 0X6);
    func_800EE88C(rdram, ctx);
        goto after_1;
    // 0x80800308: addiu       $a1, $v0, 0x6
    ctx->r5 = ADD32(ctx->r2, 0X6);
    after_1:
    // 0x8080030C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800310: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800314: jal         0x800EFC7C
    // 0x80800318: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFC7C(rdram, ctx);
        goto after_2;
    // 0x80800318: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_2:
    // 0x8080031C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(852, 0XAC4) << 16);
    // 0x80800320: lwc1        $f4, 0xAC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(852, 0XAC4));
    // 0x80800324: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080032C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800330: nop

    // 0x80800334: bc1f        L_80800340
    if (!c1cs) {
        // 0x80800338: nop
    
            goto L_80800340;
    }
    // 0x80800338: nop

    // 0x8080033C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800340:
    // 0x80800340: jr          $ra
    // 0x80800344: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800344: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bastick_updateZone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009ED20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009ED24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009ED28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009ED2C: lw          $v0, 0x128($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X128);
    // 0x8009ED30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009ED34: lwc1        $f2, 0x40($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8009ED38: lwc1        $f0, 0x60($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X60);
    // 0x8009ED3C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8009ED40: nop

    // 0x8009ED44: bc1fl       L_8009ED64
    if (!c1cs) {
        // 0x8009ED48: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8009ED64;
    }
    goto skip_0;
    // 0x8009ED48: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x8009ED4C: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8009ED50: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8009ED54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8009ED58: b           L_8009EE98
    // 0x8009ED5C: swc1        $f4, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f4.u32l;
        goto L_8009EE98;
    // 0x8009ED5C: swc1        $f4, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f4.u32l;
    // 0x8009ED60: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8009ED64:
    // 0x8009ED64: nop

    // 0x8009ED68: bc1fl       L_8009EDB0
    if (!c1cs) {
        // 0x8009ED6C: lwc1        $f8, 0x44($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
            goto L_8009EDB0;
    }
    goto skip_1;
    // 0x8009ED6C: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    skip_1:
    // 0x8009ED70: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8009ED74: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009ED78: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8009ED7C: nop

    // 0x8009ED80: bc1fl       L_8009EDB0
    if (!c1cs) {
        // 0x8009ED84: lwc1        $f8, 0x44($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
            goto L_8009EDB0;
    }
    goto skip_2;
    // 0x8009ED84: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    skip_2:
    // 0x8009ED88: sw          $t7, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r15;
    // 0x8009ED8C: lw          $v0, 0x128($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X128);
    // 0x8009ED90: lwc1        $f12, 0x60($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X60);
    // 0x8009ED94: lwc1        $f14, 0x40($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8009ED98: jal         0x8009ED08
    // 0x8009ED9C: lw          $a2, 0x44($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X44);
    bastick_calculateZonePosition(rdram, ctx);
        goto after_0;
    // 0x8009ED9C: lw          $a2, 0x44($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X44);
    after_0:
    // 0x8009EDA0: lw          $t8, 0x128($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X128);
    // 0x8009EDA4: b           L_8009EE98
    // 0x8009EDA8: swc1        $f0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f0.u32l;
        goto L_8009EE98;
    // 0x8009EDA8: swc1        $f0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f0.u32l;
    // 0x8009EDAC: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
L_8009EDB0:
    // 0x8009EDB0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8009EDB4: nop

    // 0x8009EDB8: bc1fl       L_8009EE00
    if (!c1cs) {
        // 0x8009EDBC: lwc1        $f16, 0x48($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
            goto L_8009EE00;
    }
    goto skip_3;
    // 0x8009EDBC: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    skip_3:
    // 0x8009EDC0: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8009EDC4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8009EDC8: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8009EDCC: nop

    // 0x8009EDD0: bc1fl       L_8009EE00
    if (!c1cs) {
        // 0x8009EDD4: lwc1        $f16, 0x48($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
            goto L_8009EE00;
    }
    goto skip_4;
    // 0x8009EDD4: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    skip_4:
    // 0x8009EDD8: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    // 0x8009EDDC: lw          $v0, 0x128($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X128);
    // 0x8009EDE0: lwc1        $f12, 0x60($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X60);
    // 0x8009EDE4: lwc1        $f14, 0x44($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8009EDE8: jal         0x8009ED08
    // 0x8009EDEC: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    bastick_calculateZonePosition(rdram, ctx);
        goto after_1;
    // 0x8009EDEC: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    after_1:
    // 0x8009EDF0: lw          $t0, 0x128($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X128);
    // 0x8009EDF4: b           L_8009EE98
    // 0x8009EDF8: swc1        $f0, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->f0.u32l;
        goto L_8009EE98;
    // 0x8009EDF8: swc1        $f0, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->f0.u32l;
    // 0x8009EDFC: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
L_8009EE00:
    // 0x8009EE00: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8009EE04: nop

    // 0x8009EE08: bc1fl       L_8009EE50
    if (!c1cs) {
        // 0x8009EE0C: lwc1        $f4, 0x4C($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X4C);
            goto L_8009EE50;
    }
    goto skip_5;
    // 0x8009EE0C: lwc1        $f4, 0x4C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4C);
    skip_5:
    // 0x8009EE10: lwc1        $f18, 0x4C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8009EE14: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8009EE18: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x8009EE1C: nop

    // 0x8009EE20: bc1fl       L_8009EE50
    if (!c1cs) {
        // 0x8009EE24: lwc1        $f4, 0x4C($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X4C);
            goto L_8009EE50;
    }
    goto skip_6;
    // 0x8009EE24: lwc1        $f4, 0x4C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4C);
    skip_6:
    // 0x8009EE28: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    // 0x8009EE2C: lw          $v0, 0x128($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X128);
    // 0x8009EE30: lwc1        $f12, 0x60($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X60);
    // 0x8009EE34: lwc1        $f14, 0x48($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8009EE38: jal         0x8009ED08
    // 0x8009EE3C: lw          $a2, 0x4C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4C);
    bastick_calculateZonePosition(rdram, ctx);
        goto after_2;
    // 0x8009EE3C: lw          $a2, 0x4C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4C);
    after_2:
    // 0x8009EE40: lw          $t2, 0x128($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X128);
    // 0x8009EE44: b           L_8009EE98
    // 0x8009EE48: swc1        $f0, 0x38($t2)
    MEM_W(0X38, ctx->r10) = ctx->f0.u32l;
        goto L_8009EE98;
    // 0x8009EE48: swc1        $f0, 0x38($t2)
    MEM_W(0X38, ctx->r10) = ctx->f0.u32l;
    // 0x8009EE4C: lwc1        $f4, 0x4C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4C);
L_8009EE50:
    // 0x8009EE50: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8009EE54: nop

    // 0x8009EE58: bc1fl       L_8009EE9C
    if (!c1cs) {
        // 0x8009EE5C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009EE9C;
    }
    goto skip_7;
    // 0x8009EE5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8009EE60: lwc1        $f6, 0x50($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8009EE64: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8009EE68: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8009EE6C: nop

    // 0x8009EE70: bc1fl       L_8009EE9C
    if (!c1cs) {
        // 0x8009EE74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009EE9C;
    }
    goto skip_8;
    // 0x8009EE74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x8009EE78: sw          $t3, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r11;
    // 0x8009EE7C: lw          $v0, 0x128($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X128);
    // 0x8009EE80: lwc1        $f12, 0x60($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X60);
    // 0x8009EE84: lwc1        $f14, 0x4C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8009EE88: jal         0x8009ED08
    // 0x8009EE8C: lw          $a2, 0x50($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X50);
    bastick_calculateZonePosition(rdram, ctx);
        goto after_3;
    // 0x8009EE8C: lw          $a2, 0x50($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X50);
    after_3:
    // 0x8009EE90: lw          $t4, 0x128($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X128);
    // 0x8009EE94: swc1        $f0, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->f0.u32l;
L_8009EE98:
    // 0x8009EE98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009EE9C:
    // 0x8009EE9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009EEA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009EEA4: jr          $ra
    // 0x8009EEA8: nop

    return;
    // 0x8009EEA8: nop

;}
RECOMP_FUNC void _bsswim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D80: syscall     94
    recomp_syscall_handler(rdram, ctx, 0x80083D80);
    return;
    // 0x80083D84: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800966BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800966BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800966C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800966C4: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x800966C8: jal         0x800C67E0
    // 0x800966CC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C67E0(rdram, ctx);
        goto after_0;
    // 0x800966CC: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x800966D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800966D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800966D8: jr          $ra
    // 0x800966DC: nop

    return;
    // 0x800966DC: nop

;}
RECOMP_FUNC void _chpiranha_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086DE0: syscall     458
    recomp_syscall_handler(rdram, ctx, 0x80086DE0);
    return;
    // 0x80086DE4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void bainput_should_poop_egg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097BFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097C00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097C04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097C08: jal         0x80091A58
    // 0x80097C0C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80097C0C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_0:
    // 0x80097C10: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097C14: beq         $t6, $zero, L_80097C2C
    if (ctx->r14 == 0) {
        // 0x80097C18: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80097C2C;
    }
    // 0x80097C18: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097C1C: jal         0x8008D280
    // 0x80097C20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008D280(rdram, ctx);
        goto after_1;
    // 0x80097C20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80097C24: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097C28: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80097C2C:
    // 0x80097C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097C30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097C34: jr          $ra
    // 0x80097C38: nop

    return;
    // 0x80097C38: nop

;}
