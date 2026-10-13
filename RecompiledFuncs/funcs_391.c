#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800384_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800384: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800388: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080038C: jal         0x808004CC
    // 0x80800390: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bstrexsmall_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800390: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800394: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800398: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080039C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003A4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808003A8: jal         0x8009FFD8
    // 0x808003AC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x808003AC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x808003B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808003B4: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808003B8: jal         0x8009C99C
    // 0x808003BC: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_2;
    // 0x808003BC: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_2:
    // 0x808003C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003C8: jr          $ra
    // 0x808003CC: nop

    return;
    // 0x808003CC: nop

;}
RECOMP_FUNC void func_80095388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095388: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8009538C: lh          $t6, 0xC($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XC);
    // 0x80095390: addiu       $v0, $a3, 0x3E8
    ctx->r2 = ADD32(ctx->r7, 0X3E8);
    // 0x80095394: addiu       $v1, $a2, 0xC
    ctx->r3 = ADD32(ctx->r6, 0XC);
    // 0x80095398: bltz        $t6, L_800953D4
    if (SIGNED(ctx->r14) < 0) {
        // 0x8009539C: lw          $t9, 0x0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X0);
            goto L_800953D4;
    }
    // 0x8009539C: lw          $t9, 0x0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X0);
    // 0x800953A0: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x800953A4: addu        $t7, $a0, $v0
    ctx->r15 = ADD32(ctx->r4, ctx->r2);
L_800953A8:
    // 0x800953A8: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800953AC: beql        $at, $zero, L_800953C8
    if (ctx->r1 == 0) {
        // 0x800953B0: lh          $a0, 0x4($v1)
        ctx->r4 = MEM_H(ctx->r3, 0X4);
            goto L_800953C8;
    }
    goto skip_0;
    // 0x800953B0: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
    skip_0:
    // 0x800953B4: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x800953B8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800953BC: jr          $ra
    // 0x800953C0: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    return;
    // 0x800953C0: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x800953C4: lh          $a0, 0x4($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X4);
L_800953C8:
    // 0x800953C8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800953CC: bgezl       $a0, L_800953A8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800953D0: addu        $t7, $a0, $v0
        ctx->r15 = ADD32(ctx->r4, ctx->r2);
            goto L_800953A8;
    }
    goto skip_1;
    // 0x800953D0: addu        $t7, $a0, $v0
    ctx->r15 = ADD32(ctx->r4, ctx->r2);
    skip_1:
L_800953D4:
    // 0x800953D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800953D8: jr          $ra
    // 0x800953DC: nop

    return;
    // 0x800953DC: nop

;}
RECOMP_FUNC void _badeathmatch_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085500: syscall     165
    recomp_syscall_handler(rdram, ctx, 0x80085500);
    return;
    // 0x80085504: xori        $t0, $zero, 0x4
    ctx->r8 = 0 ^ 0X4;
;}
RECOMP_FUNC void func_80800344_bsmumattack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800344: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800348: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080034C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800350: jal         0x80083808
    // 0x80800354: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsmum_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800354: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800358: jal         0x800853E0
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bawandglow_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800360: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800364: sw          $t6, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r14;
    // 0x80800368: jal         0x80800054
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800054_bsmumattack(rdram, ctx);
        goto after_2;
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800374: addiu       $a1, $zero, 0x9F
    ctx->r5 = ADD32(0, 0X9F);
    // 0x80800378: jal         0x8008CCBC
    // 0x8080037C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_3;
    // 0x8080037C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x80800380: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800384: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080038C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800390: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800394: jal         0x8009FFD8
    // 0x80800398: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_8009FFD8(rdram, ctx);
        goto after_4;
    // 0x80800398: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_4:
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A0: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x808003A4: jal         0x8009C99C
    // 0x808003A8: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_5;
    // 0x808003A8: lui         $a2, 0x4060
    ctx->r6 = S32(0X4060 << 16);
    after_5:
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B0: jal         0x8009B9B0
    // 0x808003B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x808003B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808003B8: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C0: jal         0x808001B4
    // 0x808003C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808001B4_bsmumattack(rdram, ctx);
        goto after_7;
    // 0x808003C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808003C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003D4: jr          $ra
    // 0x808003D8: nop

    return;
    // 0x808003D8: nop

;}
RECOMP_FUNC void _bapulse_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F68: syscall     144
    recomp_syscall_handler(rdram, ctx, 0x80084F68);
    return;
    // 0x80084F6C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void glsplinefind_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000AC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808000B0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808000B4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808000B8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808000BC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808000C0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808000C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808000C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808000CC: jal         0x800D7400
    // 0x808000D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800D7400(rdram, ctx);
        goto after_0;
    // 0x808000D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x808000D4: lw          $t6, 0x188($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X188);
    // 0x808000D8: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x808000DC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x808000E0: blez        $t6, L_80800148
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808000E4: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_80800148;
    }
    // 0x808000E4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x808000E8: lh          $a0, 0x184($s6)
    ctx->r4 = MEM_H(ctx->r22, 0X184);
L_808000EC:
    // 0x808000EC: jal         0x8001B798
    // 0x808000F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x808000F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_1:
    // 0x808000F4: addu        $t7, $v0, $s5
    ctx->r15 = ADD32(ctx->r2, ctx->r21);
    // 0x808000F8: jal         0x8001B798
    // 0x808000FC: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    func_8001B798(rdram, ctx);
        goto after_2;
    // 0x808000FC: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    after_2:
    // 0x80800100: lbu         $s2, 0x2($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X2);
    // 0x80800104: addiu       $s0, $v0, 0x14
    ctx->r16 = ADD32(ctx->r2, 0X14);
    // 0x80800108: blez        $s2, L_80800130
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8080010C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800130;
    }
L_8080010C:
    // 0x8080010C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800110: jal         0x800EECE0
    // 0x80800114: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EECE0(rdram, ctx);
        goto after_3;
    // 0x80800114: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80800118: beq         $v0, $zero, L_80800128
    if (ctx->r2 == 0) {
        // 0x8080011C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800128;
    }
    // 0x8080011C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800120: b           L_8080014C
    // 0x80800124: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
        goto L_8080014C;
    // 0x80800124: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_80800128:
    // 0x80800128: bne         $s1, $s2, L_8080010C
    if (ctx->r17 != ctx->r18) {
        // 0x8080012C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8080010C;
    }
    // 0x8080012C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_80800130:
    // 0x80800130: lw          $t8, 0x188($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X188);
    // 0x80800134: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80800138: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x8080013C: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80800140: bnel        $at, $zero, L_808000EC
    if (ctx->r1 != 0) {
        // 0x80800144: lh          $a0, 0x184($s6)
        ctx->r4 = MEM_H(ctx->r22, 0X184);
            goto L_808000EC;
    }
    goto skip_0;
    // 0x80800144: lh          $a0, 0x184($s6)
    ctx->r4 = MEM_H(ctx->r22, 0X184);
    skip_0:
L_80800148:
    // 0x80800148: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8080014C:
    // 0x8080014C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800150: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800154: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800158: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080015C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800160: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800164: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800168: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8080016C: jr          $ra
    // 0x80800170: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800170: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800BD268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BD26C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD270: sb          $a1, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r5;
    // 0x800BD274: jal         0x800BD28C
    // 0x800BD278: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800BD28C(rdram, ctx);
        goto after_0;
    // 0x800BD278: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x800BD27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BD280: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BD284: jr          $ra
    // 0x800BD288: nop

    return;
    // 0x800BD288: nop

;}
RECOMP_FUNC void func_80098210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098210: jr          $ra
    // 0x80098214: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    return;
    // 0x80098214: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80094510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094510: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80094514: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80094518: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8009451C: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x80094520: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80094524: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80094528: lw          $t8, 0x7E30($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7E30);
    // 0x8009452C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80094530: jr          $ra
    // 0x80094534: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    return;
    // 0x80094534: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
;}
RECOMP_FUNC void func_808007F0_chpoolkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007F4: addiu       $at, $zero, 0x1020
    ctx->r1 = ADD32(0, 0X1020);
    // 0x808007F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800800: beq         $a1, $at, L_80800824
    if (ctx->r5 == ctx->r1) {
        // 0x80800804: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800824;
    }
    // 0x80800804: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800808: addiu       $at, $zero, 0x1021
    ctx->r1 = ADD32(0, 0X1021);
    // 0x8080080C: beq         $a1, $at, L_80800824
    if (ctx->r5 == ctx->r1) {
        // 0x80800810: addiu       $at, $zero, 0x1022
        ctx->r1 = ADD32(0, 0X1022);
            goto L_80800824;
    }
    // 0x80800810: addiu       $at, $zero, 0x1022
    ctx->r1 = ADD32(0, 0X1022);
    // 0x80800814: beq         $a1, $at, L_8080083C
    if (ctx->r5 == ctx->r1) {
        // 0x80800818: addiu       $a0, $zero, 0x22
        ctx->r4 = ADD32(0, 0X22);
            goto L_8080083C;
    }
    // 0x80800818: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8080081C: b           L_8080086C
    // 0x80800820: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
        goto L_8080086C;
    // 0x80800820: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80800824:
    // 0x80800824: jal         0x80085710
    // 0x80800828: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800828: nop

    after_0:
    // 0x8080082C: jal         0x80088830
    // 0x80800830: nop

    _glcutDll_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x80800830: nop

    after_1:
    // 0x80800834: b           L_80800878
    // 0x80800838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800878;
    // 0x80800838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080083C:
    // 0x8080083C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800840: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800844: jal         0x800D0C78
    // 0x80800848: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800D0C78(rdram, ctx);
        goto after_2;
    // 0x80800848: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x8080084C: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80800850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800854: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800858: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080085C: jal         0x80102424
    // 0x80800860: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800860: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    after_3:
    // 0x80800864: b           L_80800878
    // 0x80800868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800878;
    // 0x80800868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080086C:
    // 0x8080086C: jal         0x80102424
    // 0x80800870: lw          $a1, 0x28($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X28);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x80800870: lw          $a1, 0x28($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X28);
    after_4:
    // 0x80800874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800878:
    // 0x80800878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080087C: jr          $ra
    // 0x80800880: nop

    return;
    // 0x80800880: nop

;}
RECOMP_FUNC void func_800F22B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F22B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F22B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F22BC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800F22C0: jal         0x800137F4
    // 0x800F22C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800137F4(rdram, ctx);
        goto after_0;
    // 0x800F22C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F22C8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800F22CC: jal         0x80013788
    // 0x800F22D0: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    func_80013788(rdram, ctx);
        goto after_1;
    // 0x800F22D0: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    after_1:
    // 0x800F22D4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800F22D8: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x800F22DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F22E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F22E4: jr          $ra
    // 0x800F22E8: nop

    return;
    // 0x800F22E8: nop

;}
RECOMP_FUNC void func_808009C0_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009C4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808009C8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808009CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808009D4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x808009D8: jal         0x80100094
    // 0x808009DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009E0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808009E4: addiu       $at, $zero, 0x17F3
    ctx->r1 = ADD32(0, 0X17F3);
    // 0x808009E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808009EC: beq         $a2, $at, L_80800A1C
    if (ctx->r6 == ctx->r1) {
        // 0x808009F0: addiu       $at, $zero, 0x17F7
        ctx->r1 = ADD32(0, 0X17F7);
            goto L_80800A1C;
    }
    // 0x808009F0: addiu       $at, $zero, 0x17F7
    ctx->r1 = ADD32(0, 0X17F7);
    // 0x808009F4: beq         $a2, $at, L_80800A14
    if (ctx->r6 == ctx->r1) {
        // 0x808009F8: addiu       $at, $zero, 0x1808
        ctx->r1 = ADD32(0, 0X1808);
            goto L_80800A14;
    }
    // 0x808009F8: addiu       $at, $zero, 0x1808
    ctx->r1 = ADD32(0, 0X1808);
    // 0x808009FC: beq         $a2, $at, L_80800A24
    if (ctx->r6 == ctx->r1) {
        // 0x80800A00: addiu       $at, $zero, 0x181A
        ctx->r1 = ADD32(0, 0X181A);
            goto L_80800A24;
    }
    // 0x80800A00: addiu       $at, $zero, 0x181A
    ctx->r1 = ADD32(0, 0X181A);
    // 0x80800A04: beq         $a2, $at, L_80800A24
    if (ctx->r6 == ctx->r1) {
        // 0x80800A08: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800A24;
    }
    // 0x80800A08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800A0C: b           L_80800A34
    // 0x80800A10: nop

        goto L_80800A34;
    // 0x80800A10: nop

L_80800A14:
    // 0x80800A14: b           L_80800A34
    // 0x80800A18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
        goto L_80800A34;
    // 0x80800A18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80800A1C:
    // 0x80800A1C: b           L_80800A34
    // 0x80800A20: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
        goto L_80800A34;
    // 0x80800A20: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
L_80800A24:
    // 0x80800A24: jal         0x800D211C
    // 0x80800A28: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    func_800D211C(rdram, ctx);
        goto after_1;
    // 0x80800A28: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    after_1:
    // 0x80800A2C: b           L_80800A38
    // 0x80800A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800A38;
    // 0x80800A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A34:
    // 0x80800A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A38:
    // 0x80800A38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A3C: jr          $ra
    // 0x80800A40: nop

    return;
    // 0x80800A40: nop

;}
RECOMP_FUNC void _ncpodfixpos_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800896B8: syscall     786
    recomp_syscall_handler(rdram, ctx, 0x800896B8);
    return;
    // 0x800896BC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80114E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114E80: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80114E84: addiu       $a1, $a1, 0x4A50
    ctx->r5 = ADD32(ctx->r5, 0X4A50);
    // 0x80114E88: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80114E8C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80114E90: addiu       $t7, $t7, 0x4A50
    ctx->r15 = ADD32(ctx->r15, 0X4A50);
    // 0x80114E94: beq         $t6, $zero, L_80114ECC
    if (ctx->r14 == 0) {
        // 0x80114E98: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80114ECC;
    }
    // 0x80114E98: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80114E9C: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
L_80114EA0:
    // 0x80114EA0: bne         $a0, $v0, L_80114EBC
    if (ctx->r4 != ctx->r2) {
        // 0x80114EA4: subu        $v0, $v1, $a1
        ctx->r2 = SUB32(ctx->r3, ctx->r5);
            goto L_80114EBC;
    }
    // 0x80114EA4: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // 0x80114EA8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80114EAC: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80114EB0: mflo        $v0
    ctx->r2 = lo;
    // 0x80114EB4: jr          $ra
    // 0x80114EB8: nop

    return;
    // 0x80114EB8: nop

L_80114EBC:
    // 0x80114EBC: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x80114EC0: addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
    // 0x80114EC4: bne         $v0, $zero, L_80114EA0
    if (ctx->r2 != 0) {
        // 0x80114EC8: nop
    
            goto L_80114EA0;
    }
    // 0x80114EC8: nop

L_80114ECC:
    // 0x80114ECC: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // 0x80114ED0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80114ED4: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80114ED8: mflo        $v0
    ctx->r2 = lo;
    // 0x80114EDC: nop

    // 0x80114EE0: nop

    // 0x80114EE4: jr          $ra
    // 0x80114EE8: nop

    return;
    // 0x80114EE8: nop

;}
RECOMP_FUNC void bsvan_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801104: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801108: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(427, 0X1CCC) << 16);
    // 0x8080110C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801110: jr          $ra
    // 0x80801114: lw          $v0, 0x1CCC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1CCC));
    return;
    // 0x80801114: lw          $v0, 0x1CCC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(427, 0X1CCC));
;}
RECOMP_FUNC void mlspline_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008EC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808008F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808008F4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808008F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808008FC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800900: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800904: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800908: mul.s       $f14, $f4, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8080090C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800910: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800914: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800918: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8080091C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80800920: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80800924: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800928: mul.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8080092C: add.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f4.fl;
    // 0x80800930: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80800934: mul.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80800938: beq         $v1, $v0, L_80800984
    if (ctx->r3 == ctx->r2) {
        // 0x8080093C: sub.s       $f8, $f2, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f4.fl;
            goto L_80800984;
    }
    // 0x8080093C: sub.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f4.fl;
L_80800940:
    // 0x80800940: sub.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80800944: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800948: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080094C: add.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80800950: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800954: sub.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800958: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8080095C: add.s       $f4, $f2, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80800960: swc1        $f4, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f4.u32l;
    // 0x80800964: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80800968: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8080096C: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80800970: mul.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80800974: add.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f4.fl;
    // 0x80800978: mul.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8080097C: bne         $v1, $v0, L_80800940
    if (ctx->r3 != ctx->r2) {
        // 0x80800980: sub.s       $f8, $f2, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f4.fl;
            goto L_80800940;
    }
    // 0x80800980: sub.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f4.fl;
L_80800984:
    // 0x80800984: add.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80800988: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080098C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800990: sub.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80800994: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80800998: sub.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8080099C: add.s       $f4, $f2, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x808009A0: swc1        $f4, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f4.u32l;
    // 0x808009A4: jr          $ra
    // 0x808009A8: nop

    return;
    // 0x808009A8: nop

;}
RECOMP_FUNC void func_80000658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000658: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8000065C: jr          $ra
    // 0x80000660: lw          $v0, 0x64F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X64F0);
    return;
    // 0x80000660: lw          $v0, 0x64F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X64F0);
;}
RECOMP_FUNC void idwave_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800278: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080027C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800284: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800288: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080028C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800290: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800294: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800298: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080029C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x808002A0: jal         0x80088888
    // 0x808002A4: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    _glidmake_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808002A4: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x808002A8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808002AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002B0: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x808002B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002B8: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x808002BC: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x808002C0: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x808002C4: lh          $t7, 0x2A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X2A);
    // 0x808002C8: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x808002CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808002D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002D4: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x808002D8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x808002DC: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x808002E0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808002E4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808002E8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808002EC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x808002F0: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x808002F4: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x808002F8: lh          $t9, 0x28($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X28);
    // 0x808002FC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80800300: nop

    // 0x80800304: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800308: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080030C: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80800310: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80800314: lh          $t0, 0x2C($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2C);
    // 0x80800318: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8080031C: nop

    // 0x80800320: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800324: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    // 0x80800328: lh          $t2, 0x2A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X2A);
    // 0x8080032C: lh          $t1, 0x22($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X22);
    // 0x80800330: sh          $zero, 0x28($s0)
    MEM_H(0X28, ctx->r16) = 0;
    // 0x80800334: sh          $zero, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = 0;
    // 0x80800338: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8080033C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80800340: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x80800344: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800348: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8080034C: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x80800350: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800354: add.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80800358: bltz        $v0, L_80800380
    if (SIGNED(ctx->r2) < 0) {
        // 0x8080035C: swc1        $f18, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
            goto L_80800380;
    }
    // 0x8080035C: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x80800360: beql        $at, $zero, L_80800384
    if (ctx->r1 == 0) {
        // 0x80800364: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800384;
    }
    goto skip_0;
    // 0x80800364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800368: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8080036C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2902, 0X5C0) << 16);
    // 0x80800370: lwc1        $f6, 0x5C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2902, 0X5C0));
    // 0x80800374: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800378: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080037C: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
L_80800380:
    // 0x80800380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800384:
    // 0x80800384: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800388: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080038C: jr          $ra
    // 0x80800390: nop

    return;
    // 0x80800390: nop

;}
RECOMP_FUNC void func_808080A4_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808080A4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x808080A8: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x808080AC: jr          $ra
    // 0x808080B0: sb          $a1, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r5;
    return;
    // 0x808080B0: sb          $a1, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_8080188C_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080188C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801894: jal         0x80800128
    // 0x80801898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800128_bsbfly(rdram, ctx);
        goto after_0;
    // 0x80801898: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080189C: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x808018A0: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808018A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808018A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808018AC: jal         0x80084C30
    // 0x808018B0: addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    _bafly_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x808018B0: addiu       $a2, $zero, 0xD3
    ctx->r6 = ADD32(0, 0XD3);
    after_1:
    // 0x808018B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808018B8: jal         0x800A0CF4
    // 0x808018BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_2;
    // 0x808018BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808018C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808018C8: jr          $ra
    // 0x808018CC: nop

    return;
    // 0x808018CC: nop

;}
RECOMP_FUNC void chusefeather_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800320: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(720, 0X3AC) << 16);
    // 0x80800324: jr          $ra
    // 0x80800328: addiu       $v0, $v0, 0x3AC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(720, 0X3AC));
    return;
    // 0x80800328: addiu       $v0, $v0, 0x3AC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(720, 0X3AC));
    // 0x8080032C: nop

;}
RECOMP_FUNC void func_808008E0_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808008E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008E8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808008EC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808008F0: jal         0x80100094
    // 0x808008F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008F8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x808008FC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80800900: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800904: lhu         $t7, 0x72($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X72);
    // 0x80800908: addiu       $t0, $t9, -0x2
    ctx->r8 = ADD32(ctx->r25, -0X2);
    // 0x8080090C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800910: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800914: beq         $t6, $t8, L_80800BCC
    if (ctx->r14 == ctx->r24) {
        // 0x80800918: sltiu       $at, $t0, 0x8
        ctx->r1 = ctx->r8 < 0X8 ? 1 : 0;
            goto L_80800BCC;
    }
    // 0x80800918: sltiu       $at, $t0, 0x8
    ctx->r1 = ctx->r8 < 0X8 ? 1 : 0;
    // 0x8080091C: beq         $at, $zero, L_80800BC0
    if (ctx->r1 == 0) {
        // 0x80800920: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80800BC0;
    }
    // 0x80800920: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800924: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2208, 0X1300) << 16);
    // 0x80800928: addu        $at, $at, $t0
    gpr jr_addend_80800930 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8080092C: lw          $t0, 0x1300($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2208, 0X1300));
    // 0x80800930: jr          $t0
    // 0x80800934: nop

    switch (jr_addend_80800930 >> 2) {
        case 0: goto L_80800938; break;
        case 1: goto L_80800A54; break;
        case 2: goto L_808009A8; break;
        case 3: goto L_80800A04; break;
        case 4: goto L_80800AF4; break;
        case 5: goto L_80800B38; break;
        case 6: goto L_80800BB0; break;
        case 7: goto L_80800A74; break;
        default: switch_error(__func__, 0x80800930, 0x80801300);
    }
    // 0x80800934: nop

L_80800938:
    // 0x80800938: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    // 0x8080093C: jal         0x80088178
    // 0x80800940: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800940: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800944: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800948: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    // 0x8080094C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800950: jal         0x800D2498
    // 0x80800954: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    func_800D2498(rdram, ctx);
        goto after_2;
    // 0x80800954: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    after_2:
    // 0x80800958: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8080095C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800960: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800964: lhu         $v1, 0x76($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X76);
    // 0x80800968: srl         $t2, $v1, 7
    ctx->r10 = S32(U32(ctx->r3) >> 7);
    // 0x8080096C: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x80800970: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80800974: bgez        $t2, L_80800988
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800978: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800988;
    }
    // 0x80800978: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080097C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800980: nop

    // 0x80800984: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80800988:
    // 0x80800988: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8080098C: jal         0x800CE8D8
    // 0x80800990: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    func_800CE8D8(rdram, ctx);
        goto after_3;
    // 0x80800990: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    after_3:
    // 0x80800994: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800998: jal         0x800CE88C
    // 0x8080099C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_4;
    // 0x8080099C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808009A0: b           L_80800BC0
    // 0x808009A4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_80800BC0;
    // 0x808009A4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_808009A8:
    // 0x808009A8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x808009AC: jal         0x800FC63C
    // 0x808009B0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800FC63C(rdram, ctx);
        goto after_5;
    // 0x808009B0: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_5:
    // 0x808009B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808009B8: jal         0x80800BDC
    // 0x808009BC: addiu       $a1, $zero, 0x1372
    ctx->r5 = ADD32(0, 0X1372);
    func_80800BDC_chclinker(rdram, ctx);
        goto after_6;
    // 0x808009BC: addiu       $a1, $zero, 0x1372
    ctx->r5 = ADD32(0, 0X1372);
    after_6:
    // 0x808009C0: jal         0x800CEAA8
    // 0x808009C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_7;
    // 0x808009C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x808009C8: beq         $v0, $zero, L_808009D8
    if (ctx->r2 == 0) {
        // 0x808009CC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808009D8;
    }
    // 0x808009CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808009D0: jal         0x800CE88C
    // 0x808009D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_8;
    // 0x808009D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
L_808009D8:
    // 0x808009D8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x808009DC: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    // 0x808009E0: lw          $a0, 0x3C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X3C);
    // 0x808009E4: beq         $a0, $zero, L_808009FC
    if (ctx->r4 == 0) {
        // 0x808009E8: nop
    
            goto L_808009FC;
    }
    // 0x808009E8: nop

    // 0x808009EC: jal         0x8010114C
    // 0x808009F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_9;
    // 0x808009F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x808009F4: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x808009F8: sw          $zero, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = 0;
L_808009FC:
    // 0x808009FC: b           L_80800BC0
    // 0x80800A00: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_80800BC0;
    // 0x80800A00: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_80800A04:
    // 0x80800A04: jal         0x800D284C
    // 0x80800A08: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    func_800D284C(rdram, ctx);
        goto after_10;
    // 0x80800A08: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    after_10:
    // 0x80800A0C: jal         0x800D395C
    // 0x80800A10: nop

    func_800D395C(rdram, ctx);
        goto after_11;
    // 0x80800A10: nop

    after_11:
    // 0x80800A14: beq         $v0, $zero, L_80800A2C
    if (ctx->r2 == 0) {
        // 0x80800A18: nop
    
            goto L_80800A2C;
    }
    // 0x80800A18: nop

    // 0x80800A1C: jal         0x800D284C
    // 0x80800A20: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    func_800D284C(rdram, ctx);
        goto after_12;
    // 0x80800A20: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_12:
    // 0x80800A24: b           L_80800A4C
    // 0x80800A28: nop

        goto L_80800A4C;
    // 0x80800A28: nop

L_80800A2C:
    // 0x80800A2C: jal         0x800CEAA8
    // 0x80800A30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_13;
    // 0x80800A30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80800A34: beq         $v0, $zero, L_80800A44
    if (ctx->r2 == 0) {
        // 0x80800A38: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800A44;
    }
    // 0x80800A38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800A3C: jal         0x800CE88C
    // 0x80800A40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_14;
    // 0x80800A40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
L_80800A44:
    // 0x80800A44: jal         0x800D284C
    // 0x80800A48: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    func_800D284C(rdram, ctx);
        goto after_15;
    // 0x80800A48: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_15:
L_80800A4C:
    // 0x80800A4C: b           L_80800BC0
    // 0x80800A50: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_80800BC0;
    // 0x80800A50: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_80800A54:
    // 0x80800A54: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800A58: jal         0x80108B04
    // 0x80800A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_16;
    // 0x80800A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80800A60: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800A64: jal         0x80800BDC
    // 0x80800A68: addiu       $a1, $zero, 0x1371
    ctx->r5 = ADD32(0, 0X1371);
    func_80800BDC_chclinker(rdram, ctx);
        goto after_17;
    // 0x80800A68: addiu       $a1, $zero, 0x1371
    ctx->r5 = ADD32(0, 0X1371);
    after_17:
    // 0x80800A6C: b           L_80800BC0
    // 0x80800A70: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_80800BC0;
    // 0x80800A70: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_80800A74:
    // 0x80800A74: jal         0x800F54E4
    // 0x80800A78: nop

    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x80800A78: nop

    after_18:
    // 0x80800A7C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800A80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800A88: jal         0x800F49D4
    // 0x80800A8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F49D4(rdram, ctx);
        goto after_19;
    // 0x80800A8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x80800A90: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800A94: jal         0x800F7B9C
    // 0x80800A98: addiu       $a1, $zero, 0x8F
    ctx->r5 = ADD32(0, 0X8F);
    func_800F7B9C(rdram, ctx);
        goto after_20;
    // 0x80800A98: addiu       $a1, $zero, 0x8F
    ctx->r5 = ADD32(0, 0X8F);
    after_20:
    // 0x80800A9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800AA0: jal         0x800F7B9C
    // 0x80800AA4: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    func_800F7B9C(rdram, ctx);
        goto after_21;
    // 0x80800AA4: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    after_21:
    // 0x80800AA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800AAC: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    // 0x80800AB0: jal         0x800F7C58
    // 0x80800AB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F7C58(rdram, ctx);
        goto after_22;
    // 0x80800AB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
    // 0x80800AB8: jal         0x800D211C
    // 0x80800ABC: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    func_800D211C(rdram, ctx);
        goto after_23;
    // 0x80800ABC: addiu       $a0, $zero, 0x94
    ctx->r4 = ADD32(0, 0X94);
    after_23:
    // 0x80800AC0: beq         $v0, $zero, L_80800AD0
    if (ctx->r2 == 0) {
        // 0x80800AC4: addiu       $a1, $zero, 0xCEC
        ctx->r5 = ADD32(0, 0XCEC);
            goto L_80800AD0;
    }
    // 0x80800AC4: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x80800AC8: b           L_80800AD0
    // 0x80800ACC: addiu       $a1, $zero, 0x137C
    ctx->r5 = ADD32(0, 0X137C);
        goto L_80800AD0;
    // 0x80800ACC: addiu       $a1, $zero, 0x137C
    ctx->r5 = ADD32(0, 0X137C);
L_80800AD0:
    // 0x80800AD0: jal         0x80800BDC
    // 0x80800AD4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80800BDC_chclinker(rdram, ctx);
        goto after_24;
    // 0x80800AD4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_24:
    // 0x80800AD8: jal         0x800F54E4
    // 0x80800ADC: nop

    func_800F54E4(rdram, ctx);
        goto after_25;
    // 0x80800ADC: nop

    after_25:
    // 0x80800AE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800AE4: jal         0x800F7F98
    // 0x80800AE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_26;
    // 0x80800AE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80800AEC: b           L_80800BC0
    // 0x80800AF0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_80800BC0;
    // 0x80800AF0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_80800AF4:
    // 0x80800AF4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800AF8: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80800AFC: addiu       $a0, $zero, 0x103
    ctx->r4 = ADD32(0, 0X103);
    // 0x80800B00: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x80800B04: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80800B08: jal         0x800D2498
    // 0x80800B0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_27;
    // 0x80800B0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_27:
    // 0x80800B10: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B14: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    // 0x80800B18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B1C: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800B20: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800B24: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800B28: jal         0x800D2498
    // 0x80800B2C: nop

    func_800D2498(rdram, ctx);
        goto after_28;
    // 0x80800B2C: nop

    after_28:
    // 0x80800B30: b           L_80800BC0
    // 0x80800B34: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_80800BC0;
    // 0x80800B34: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_80800B38:
    // 0x80800B38: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800B3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800B40: addiu       $a1, $zero, 0x94
    ctx->r5 = ADD32(0, 0X94);
    // 0x80800B44: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800B48: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800B4C: jal         0x800D2054
    // 0x80800B50: nop

    func_800D2054(rdram, ctx);
        goto after_29;
    // 0x80800B50: nop

    after_29:
    // 0x80800B54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800B58: beq         $v0, $at, L_80800B7C
    if (ctx->r2 == ctx->r1) {
        // 0x80800B5C: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_80800B7C;
    }
    // 0x80800B5C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80800B60: beq         $v0, $zero, L_80800B88
    if (ctx->r2 == 0) {
        // 0x80800B64: addiu       $t8, $zero, 0x137E
        ctx->r24 = ADD32(0, 0X137E);
            goto L_80800B88;
    }
    // 0x80800B64: addiu       $t8, $zero, 0x137E
    ctx->r24 = ADD32(0, 0X137E);
    // 0x80800B68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B6C: beq         $v0, $at, L_80800B90
    if (ctx->r2 == ctx->r1) {
        // 0x80800B70: addiu       $t9, $zero, 0x137D
        ctx->r25 = ADD32(0, 0X137D);
            goto L_80800B90;
    }
    // 0x80800B70: addiu       $t9, $zero, 0x137D
    ctx->r25 = ADD32(0, 0X137D);
    // 0x80800B74: b           L_80800B94
    // 0x80800B78: nop

        goto L_80800B94;
    // 0x80800B78: nop

L_80800B7C:
    // 0x80800B7C: addiu       $t6, $zero, 0x137F
    ctx->r14 = ADD32(0, 0X137F);
    // 0x80800B80: b           L_80800B94
    // 0x80800B84: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
        goto L_80800B94;
    // 0x80800B84: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800B88:
    // 0x80800B88: b           L_80800B94
    // 0x80800B8C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
        goto L_80800B94;
    // 0x80800B8C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_80800B90:
    // 0x80800B90: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_80800B94:
    // 0x80800B94: jal         0x800FC63C
    // 0x80800B98: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800FC63C(rdram, ctx);
        goto after_30;
    // 0x80800B98: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_30:
    // 0x80800B9C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800BA0: jal         0x80800BDC
    // 0x80800BA4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80800BDC_chclinker(rdram, ctx);
        goto after_31;
    // 0x80800BA4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_31:
    // 0x80800BA8: b           L_80800BC0
    // 0x80800BAC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_80800BC0;
    // 0x80800BAC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_80800BB0:
    // 0x80800BB0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800BB4: jal         0x80800BDC
    // 0x80800BB8: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    func_80800BDC_chclinker(rdram, ctx);
        goto after_32;
    // 0x80800BB8: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    after_32:
    // 0x80800BBC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_80800BC0:
    // 0x80800BC0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800BC4: jal         0x80101FDC
    // 0x80800BC8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80101FDC(rdram, ctx);
        goto after_33;
    // 0x80800BC8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_33:
L_80800BCC:
    // 0x80800BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BD0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800BD4: jr          $ra
    // 0x80800BD8: nop

    return;
    // 0x80800BD8: nop

;}
RECOMP_FUNC void _basub_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851C8: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x800851C8);
    return;
    // 0x800851CC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _bstrexlarge_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084068: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80084068);
    return;
    // 0x8008406C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800B7B38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7B38: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7B3C: jr          $ra
    // 0x800B7B40: sb          $a0, -0x7E6F($at)
    MEM_B(-0X7E6F, ctx->r1) = ctx->r4;
    return;
    // 0x800B7B40: sb          $a0, -0x7E6F($at)
    MEM_B(-0X7E6F, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void bsbtrot_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801628: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080162C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(124, 0X2E80) << 16);
    // 0x80801630: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801634: jr          $ra
    // 0x80801638: lw          $v0, 0x2E80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2E80));
    return;
    // 0x80801638: lw          $v0, 0x2E80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2E80));
;}
RECOMP_FUNC void func_800CA558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_set_fov(rdram, ctx);
    // 0x800CA558: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800CA55C: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x800CA560: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CA564: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CA568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA56C: mul.s       $f12, $f14, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x800CA570: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CA574: swc1        $f14, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f14.u32l;
    // 0x800CA578: jal         0x800139F8
    // 0x800CA57C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_800139F8(rdram, ctx);
        goto after_0;
    // 0x800CA57C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800CA580: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CA584: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CA588: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CA58C: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CA590: swc1        $f8, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->f8.u32l;
    // 0x800CA594: jal         0x800CA218
    // 0x800CA598: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800CA218(rdram, ctx);
        goto after_1;
    // 0x800CA598: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800CA59C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CA5A0: jal         0x800CA2A8
    // 0x800CA5A4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800CA2A8(rdram, ctx);
        goto after_2;
    // 0x800CA5A4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800CA5A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA5AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CA5B0: jr          $ra
    // 0x800CA5B4: nop

    return;
    // 0x800CA5B4: nop

;}
RECOMP_FUNC void func_800F6720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6720: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6724: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6728: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F672C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F6730: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F6734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6738: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800F673C: jal         0x8009E71C
    // 0x800F6740: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009E71C(rdram, ctx);
        goto after_0;
    // 0x800F6740: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F6744: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F6748: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800F674C: bne         $t7, $zero, L_800F6764
    if (ctx->r15 != 0) {
        // 0x800F6750: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F6764;
    }
    // 0x800F6750: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F6754: jal         0x8008DE74
    // 0x800F6758: nop

    func_8008DE74(rdram, ctx);
        goto after_1;
    // 0x800F6758: nop

    after_1:
    // 0x800F675C: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x800F6760: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800F6764:
    // 0x800F6764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6768: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F676C: jr          $ra
    // 0x800F6770: nop

    return;
    // 0x800F6770: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_52(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802CD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802CD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802CD8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802CDC: jal         0x80800538
    // 0x80802CE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800538_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80802CE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80802CE4: jal         0x808029D8
    // 0x80802CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808029D8_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80802CE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80802CEC: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80802CF0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80802CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802CF8: jal         0x8008CB3C
    // 0x80802CFC: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_2;
    // 0x80802CFC: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    after_2:
    // 0x80802D00: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x80802D04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80802D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802D0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802D10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80802D14: jal         0x8009FFD8
    // 0x80802D18: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    func_8009FFD8(rdram, ctx);
        goto after_3;
    // 0x80802D18: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_3:
    // 0x80802D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802D20: jal         0x8009B9B0
    // 0x80802D24: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80802D24: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80802D28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802D2C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802D30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802D34: jr          $ra
    // 0x80802D38: nop

    return;
    // 0x80802D38: nop

;}
RECOMP_FUNC void func_80110424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110424: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80110428: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8011042C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80110430: lh          $a0, 0x7372($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X7372);
    // 0x80110434: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80110438: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8011043C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80110440: jal         0x8001ACCC
    // 0x80110444: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x80110444: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80110448: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8011044C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80110450: jal         0x8002D6E0
    // 0x80110454: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _bzero(rdram, ctx);
        goto after_1;
    // 0x80110454: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80110458: jal         0x80110280
    // 0x8011045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110280(rdram, ctx);
        goto after_2;
    // 0x8011045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80110460: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80110464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80110468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8011046C: sw          $t6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r14;
    // 0x80110470: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80110474: jal         0x80110720
    // 0x80110478: sw          $t7, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r15;
    func_80110720(rdram, ctx);
        goto after_3;
    // 0x80110478: sw          $t7, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r15;
    after_3:
    // 0x8011047C: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    // 0x80110480: addiu       $a1, $s0, 0x74
    ctx->r5 = ADD32(ctx->r16, 0X74);
    // 0x80110484: jal         0x8010FFB0
    // 0x80110488: addiu       $a2, $s0, 0x80
    ctx->r6 = ADD32(ctx->r16, 0X80);
    func_8010FFB0(rdram, ctx);
        goto after_4;
    // 0x80110488: addiu       $a2, $s0, 0x80
    ctx->r6 = ADD32(ctx->r16, 0X80);
    after_4:
    // 0x8011048C: jal         0x800893D0
    // 0x80110490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _ncba1p_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80110490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80110494: jal         0x80112398
    // 0x80110498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80112398(rdram, ctx);
        goto after_6;
    // 0x80110498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8011049C: jal         0x80089388
    // 0x801104A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _ncbaspline_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x801104A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801104A4: jal         0x8011337C
    // 0x801104A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8011337C(rdram, ctx);
        goto after_8;
    // 0x801104A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801104AC: jal         0x80111348
    // 0x801104B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80111348(rdram, ctx);
        goto after_9;
    // 0x801104B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x801104B4: jal         0x80115FB0
    // 0x801104B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80115FB0(rdram, ctx);
        goto after_10;
    // 0x801104B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801104BC: jal         0x801125B8
    // 0x801104C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801125B8(rdram, ctx);
        goto after_11;
    // 0x801104C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x801104C4: jal         0x80110C88
    // 0x801104C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110C88(rdram, ctx);
        goto after_12;
    // 0x801104C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x801104CC: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x801104D0: sb          $zero, 0x72($s0)
    MEM_B(0X72, ctx->r16) = 0;
    // 0x801104D4: sb          $zero, 0x71($s0)
    MEM_B(0X71, ctx->r16) = 0;
    // 0x801104D8: jal         0x800EFD24
    // 0x801104DC: addiu       $a0, $s0, 0x8C
    ctx->r4 = ADD32(ctx->r16, 0X8C);
    func_800EFD24(rdram, ctx);
        goto after_13;
    // 0x801104DC: addiu       $a0, $s0, 0x8C
    ctx->r4 = ADD32(ctx->r16, 0X8C);
    after_13:
    // 0x801104E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801104E4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801104E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801104EC: jr          $ra
    // 0x801104F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801104F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80013A7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013A7C: lui         $at, 0x3E34
    ctx->r1 = S32(0X3E34 << 16);
    // 0x80013A80: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80013A84: or          $a3, $ra, $zero
    ctx->r7 = ctx->r31 | 0;
    // 0x80013A88: jal         0x80013ABC
    // 0x80013A8C: nop

    func_80013ABC(rdram, ctx);
        goto after_0;
    // 0x80013A8C: nop

    after_0:
    // 0x80013A90: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80013A94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80013A98: jr          $ra
    // 0x80013A9C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    return;
    // 0x80013A9C: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
;}
RECOMP_FUNC void _chchuffy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C28: syscall     432
    recomp_syscall_handler(rdram, ctx, 0x80086C28);
    return;
    // 0x80086C2C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800D24_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D24: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800D28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D34: jal         0x8008E35C
    // 0x80800D38: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    player_inWater(rdram, ctx);
        goto after_0;
    // 0x80800D38: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800D3C: beq         $v0, $zero, L_80800D48
    if (ctx->r2 == 0) {
        // 0x80800D40: addiu       $t6, $zero, 0x160
        ctx->r14 = ADD32(0, 0X160);
            goto L_80800D48;
    }
    // 0x80800D40: addiu       $t6, $zero, 0x160
    ctx->r14 = ADD32(0, 0X160);
    // 0x80800D44: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_80800D48:
    // 0x80800D48: jal         0x8008E078
    // 0x80800D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_1;
    // 0x80800D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800D50: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800D54: jal         0x8009650C
    // 0x80800D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009650C(rdram, ctx);
        goto after_2;
    // 0x80800D58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800D5C: bne         $v0, $zero, L_80800D74
    if (ctx->r2 != 0) {
        // 0x80800D60: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80800D74;
    }
    // 0x80800D60: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800D64: bnel        $t7, $zero, L_80800D78
    if (ctx->r15 != 0) {
        // 0x80800D68: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_80800D78;
    }
    goto skip_0;
    // 0x80800D68: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800D6C: b           L_80800EA0
    // 0x80800D70: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
        goto L_80800EA0;
    // 0x80800D70: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_80800D74:
    // 0x80800D74: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_80800D78:
    // 0x80800D78: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D80: beq         $t8, $zero, L_80800DA0
    if (ctx->r24 == 0) {
        // 0x80800D84: nop
    
            goto L_80800DA0;
    }
    // 0x80800D84: nop

    // 0x80800D88: jal         0x800963C0
    // 0x80800D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800963C0(rdram, ctx);
        goto after_3;
    // 0x80800D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800D90: jal         0x80096628
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096628(rdram, ctx);
        goto after_4;
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800D98: b           L_80800DB4
    // 0x80800D9C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_80800DB4;
    // 0x80800D9C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80800DA0:
    // 0x80800DA0: jal         0x80096440
    // 0x80800DA4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80096440(rdram, ctx);
        goto after_5;
    // 0x80800DA4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_5:
    // 0x80800DA8: jal         0x80096434
    // 0x80800DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096434(rdram, ctx);
        goto after_6;
    // 0x80800DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800DB0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80800DB4:
    // 0x80800DB4: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80800DB8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800DBC: jal         0x800EE7F8
    // 0x80800DC0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800DC0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_7:
    // 0x80800DC4: jal         0x800EF2A0
    // 0x80800DC8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EF2A0(rdram, ctx);
        goto after_8;
    // 0x80800DC8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_8:
    // 0x80800DCC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800DD0: jal         0x800EEAA4
    // 0x80800DD4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EEAA4(rdram, ctx);
        goto after_9;
    // 0x80800DD4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_9:
    // 0x80800DD8: jal         0x800F2100
    // 0x80800DDC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_10;
    // 0x80800DDC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_10:
    // 0x80800DE0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80800DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DE8: jal         0x80095738
    // 0x80800DEC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    baflag_isTrue(rdram, ctx);
        goto after_11;
    // 0x80800DEC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_11:
    // 0x80800DF0: bne         $v0, $zero, L_80800E04
    if (ctx->r2 != 0) {
        // 0x80800DF4: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_80800E04;
    }
    // 0x80800DF4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800DF8: andi        $t0, $t9, 0x80
    ctx->r8 = ctx->r25 & 0X80;
    // 0x80800DFC: beq         $t0, $zero, L_80800E18
    if (ctx->r8 == 0) {
        // 0x80800E00: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(236, 0X1BF0) << 16);
            goto L_80800E18;
    }
    // 0x80800E00: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(236, 0X1BF0) << 16);
L_80800E04:
    // 0x80800E04: jal         0x80800974
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800974_bskazfly(rdram, ctx);
        goto after_12;
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800E0C: addiu       $t1, $zero, 0x173
    ctx->r9 = ADD32(0, 0X173);
    // 0x80800E10: b           L_80800E9C
    // 0x80800E14: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
        goto L_80800E9C;
    // 0x80800E14: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
L_80800E18:
    // 0x80800E18: lwc1        $f4, 0x1BF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(236, 0X1BF0));
    // 0x80800E1C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800E20: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(236, 0X1BF4) << 16);
    // 0x80800E24: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800E28: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800E2C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80800E30: bc1f        L_80800E90
    if (!c1cs) {
        // 0x80800E34: nop
    
            goto L_80800E90;
    }
    // 0x80800E34: nop

    // 0x80800E38: lwc1        $f10, 0x1BF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(236, 0X1BF4));
    // 0x80800E3C: addiu       $t4, $zero, 0x176
    ctx->r12 = ADD32(0, 0X176);
    // 0x80800E40: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800E44: nop

    // 0x80800E48: bc1f        L_80800E88
    if (!c1cs) {
        // 0x80800E4C: nop
    
            goto L_80800E88;
    }
    // 0x80800E4C: nop

    // 0x80800E50: jal         0x80800974
    // 0x80800E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800974_bskazfly(rdram, ctx);
        goto after_13;
    // 0x80800E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E5C: jal         0x800A17A8
    // 0x80800E60: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800A17A8(rdram, ctx);
        goto after_14;
    // 0x80800E60: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_14:
    // 0x80800E64: jal         0x800A1718
    // 0x80800E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_15;
    // 0x80800E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800E6C: beq         $v0, $zero, L_80800E80
    if (ctx->r2 == 0) {
        // 0x80800E70: addiu       $t3, $zero, 0x101
        ctx->r11 = ADD32(0, 0X101);
            goto L_80800E80;
    }
    // 0x80800E70: addiu       $t3, $zero, 0x101
    ctx->r11 = ADD32(0, 0X101);
    // 0x80800E74: addiu       $t2, $zero, 0x177
    ctx->r10 = ADD32(0, 0X177);
    // 0x80800E78: b           L_80800E9C
    // 0x80800E7C: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
        goto L_80800E9C;
    // 0x80800E7C: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
L_80800E80:
    // 0x80800E80: b           L_80800E9C
    // 0x80800E84: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
        goto L_80800E9C;
    // 0x80800E84: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
L_80800E88:
    // 0x80800E88: b           L_80800E9C
    // 0x80800E8C: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
        goto L_80800E9C;
    // 0x80800E8C: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
L_80800E90:
    // 0x80800E90: beq         $t5, $zero, L_80800E9C
    if (ctx->r13 == 0) {
        // 0x80800E94: addiu       $t6, $zero, 0x176
        ctx->r14 = ADD32(0, 0X176);
            goto L_80800E9C;
    }
    // 0x80800E94: addiu       $t6, $zero, 0x176
    ctx->r14 = ADD32(0, 0X176);
    // 0x80800E98: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_80800E9C:
    // 0x80800E9C: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_80800EA0:
    // 0x80800EA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800EA8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800EAC: jr          $ra
    // 0x80800EB0: nop

    return;
    // 0x80800EB0: nop

;}
RECOMP_FUNC void func_808034BC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808034BC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808034C0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808034C4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808034C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808034CC: sltiu       $at, $a3, 0x6
    ctx->r1 = ctx->r7 < 0X6 ? 1 : 0;
    // 0x808034D0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x808034D4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808034D8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x808034DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808034E0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808034E4: beq         $at, $zero, L_808035E8
    if (ctx->r1 == 0) {
        // 0x808034E8: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_808035E8;
    }
    // 0x808034E8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x808034EC: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x808034F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7CD0) << 16);
    // 0x808034F4: addu        $at, $at, $t6
    gpr jr_addend_808034FC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808034F8: lw          $t6, 0x7CD0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CD0));
    // 0x808034FC: jr          $t6
    // 0x80803500: nop

    switch (jr_addend_808034FC >> 2) {
        case 0: goto L_80803504; break;
        case 1: goto L_808035E8; break;
        case 2: goto L_80803554; break;
        case 3: goto L_80803554; break;
        case 4: goto L_80803518; break;
        case 5: goto L_80803540; break;
        default: switch_error(__func__, 0x808034FC, 0x80807CD0);
    }
    // 0x80803500: nop

L_80803504:
    // 0x80803504: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803508: jal         0x80803420
    // 0x8080350C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80803420_chgameselect(rdram, ctx);
        goto after_0;
    // 0x8080350C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x80803510: b           L_808035EC
    // 0x80803514: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808035EC;
    // 0x80803514: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803518:
    // 0x80803518: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080351C: jal         0x80087D38
    // 0x80803520: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80803520: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80803524: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80803528: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080352C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80803530: jal         0x80803604
    // 0x80803534: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80803604_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80803534: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80803538: b           L_808035EC
    // 0x8080353C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808035EC;
    // 0x8080353C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803540:
    // 0x80803540: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80803544: jal         0x80087DC0
    // 0x80803548: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_37(rdram, ctx);
        goto after_3;
    // 0x80803548: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080354C: b           L_808035EC
    // 0x80803550: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808035EC;
    // 0x80803550: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80803554:
    // 0x80803554: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80803558: jal         0x80100094
    // 0x8080355C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x8080355C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80803560: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80803564: lw          $a0, 0x3C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X3C);
    // 0x80803568: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8080356C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80803570: jal         0x80800AEC
    // 0x80803574: addiu       $a3, $zero, 0xFC
    ctx->r7 = ADD32(0, 0XFC);
    func_80800AEC_chgameselect(rdram, ctx);
        goto after_5;
    // 0x80803574: addiu       $a3, $zero, 0xFC
    ctx->r7 = ADD32(0, 0XFC);
    after_5:
    // 0x80803578: lw          $t7, 0x2C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X2C);
    // 0x8080357C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80803580: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80803584: blez        $t7, L_808035CC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80803588: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_808035CC;
    }
    // 0x80803588: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_8080358C:
    // 0x8080358C: jal         0x80087D20
    // 0x80803590: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_17(rdram, ctx);
        goto after_6;
    // 0x80803590: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x80803594: beq         $v0, $zero, L_808035A4
    if (ctx->r2 == 0) {
        // 0x80803598: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_808035A4;
    }
    // 0x80803598: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8080359C: b           L_808035A8
    // 0x808035A0: addiu       $a3, $zero, 0xFE
    ctx->r7 = ADD32(0, 0XFE);
        goto L_808035A8;
    // 0x808035A0: addiu       $a3, $zero, 0xFE
    ctx->r7 = ADD32(0, 0XFE);
L_808035A4:
    // 0x808035A4: addiu       $a3, $zero, 0xFD
    ctx->r7 = ADD32(0, 0XFD);
L_808035A8:
    // 0x808035A8: lw          $a0, 0x3C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X3C);
    // 0x808035AC: jal         0x80800AEC
    // 0x808035B0: lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X0);
    func_80800AEC_chgameselect(rdram, ctx);
        goto after_7;
    // 0x808035B0: lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X0);
    after_7:
    // 0x808035B4: lw          $t8, 0x2C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X2C);
    // 0x808035B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808035BC: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x808035C0: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x808035C4: bnel        $at, $zero, L_8080358C
    if (ctx->r1 != 0) {
        // 0x808035C8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8080358C;
    }
    goto skip_0;
    // 0x808035C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
L_808035CC:
    // 0x808035CC: jal         0x80802FE4
    // 0x808035D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80802FE4_chgameselect(rdram, ctx);
        goto after_8;
    // 0x808035D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x808035D4: lw          $a0, 0x3C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X3C);
    // 0x808035D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808035DC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x808035E0: jal         0x80800AEC
    // 0x808035E4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    func_80800AEC_chgameselect(rdram, ctx);
        goto after_9;
    // 0x808035E4: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    after_9:
L_808035E8:
    // 0x808035E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808035EC:
    // 0x808035EC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808035F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808035F4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808035F8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808035FC: jr          $ra
    // 0x80803600: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80803600: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800FC97C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC97C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FC980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FC984: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800FC988: jal         0x800FB5F8
    // 0x800FC98C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FC98C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800FC990: beq         $v0, $zero, L_800FC9A4
    if (ctx->r2 == 0) {
        // 0x800FC994: lwc1        $f4, 0x1C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_800FC9A4;
    }
    // 0x800FC994: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800FC998: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x800FC99C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800FC9A0: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
L_800FC9A4:
    // 0x800FC9A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FC9A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FC9AC: jr          $ra
    // 0x800FC9B0: nop

    return;
    // 0x800FC9B0: nop

;}
RECOMP_FUNC void dbmorph_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800734: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800738: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080073C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800740: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800744: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800748: jal         0x80800000
    // 0x8080074C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80800000_dbmorph(rdram, ctx);
        goto after_0;
    // 0x8080074C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80800750: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800754: lh          $s0, 0x6($v0)
    ctx->r16 = MEM_H(ctx->r2, 0X6);
    // 0x80800758: jal         0x800B2190
    // 0x8080075C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_800B2190(rdram, ctx);
        goto after_1;
    // 0x8080075C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x80800760: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80800764: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800768: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8080076C: lhu         $t7, 0x16($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X16);
    // 0x80800770: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80800774: beq         $t8, $zero, L_8080078C
    if (ctx->r24 == 0) {
        // 0x80800778: nop
    
            goto L_8080078C;
    }
    // 0x80800778: nop

    // 0x8080077C: lh          $t1, 0x4($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X4);
    // 0x80800780: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80800784: b           L_808007A4
    // 0x80800788: addu        $a2, $t2, $v0
    ctx->r6 = ADD32(ctx->r10, ctx->r2);
        goto L_808007A4;
    // 0x80800788: addu        $a2, $t2, $v0
    ctx->r6 = ADD32(ctx->r10, ctx->r2);
L_8080078C:
    // 0x8080078C: jal         0x800B2190
    // 0x80800790: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_800B2190(rdram, ctx);
        goto after_2;
    // 0x80800790: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_2:
    // 0x80800794: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80800798: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x8080079C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x808007A0: addu        $a2, $v0, $t5
    ctx->r6 = ADD32(ctx->r2, ctx->r13);
L_808007A4:
    // 0x808007A4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808007A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808007AC: jal         0x80100480
    // 0x808007B0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80100480(rdram, ctx);
        goto after_3;
    // 0x808007B0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_3:
    // 0x808007B4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808007B8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808007BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808007C0: beq         $s0, $zero, L_80800804
    if (ctx->r16 == 0) {
        // 0x808007C4: or          $t0, $s0, $zero
        ctx->r8 = ctx->r16 | 0;
            goto L_80800804;
    }
    // 0x808007C4: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
L_808007C8:
    // 0x808007C8: lhu         $t6, 0x6($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X6);
    // 0x808007CC: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x808007D0: beq         $t7, $zero, L_808007F8
    if (ctx->r15 == 0) {
        // 0x808007D4: nop
    
            goto L_808007F8;
    }
    // 0x808007D4: nop

    // 0x808007D8: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x808007DC: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x808007E0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x808007E4: sh          $t8, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r24;
    // 0x808007E8: lh          $t9, 0x2($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X2);
    // 0x808007EC: sh          $t9, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r25;
    // 0x808007F0: lh          $t1, 0x4($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X4);
    // 0x808007F4: sh          $t1, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r9;
L_808007F8:
    // 0x808007F8: bne         $t0, $zero, L_808007C8
    if (ctx->r8 != 0) {
        // 0x808007FC: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_808007C8;
    }
    // 0x808007FC: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80800800: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
L_80800804:
    // 0x80800804: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80800808: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8080080C: lh          $a1, 0x0($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X0);
    // 0x80800810: jal         0x800ADE2C
    // 0x80800814: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_800ADE2C(rdram, ctx);
        goto after_4;
    // 0x80800814: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_4:
    // 0x80800818: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080081C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800820: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800824: jal         0x80116568
    // 0x80800828: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80116568(rdram, ctx);
        goto after_5;
    // 0x80800828: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_5:
    // 0x8080082C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80800830: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800834: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80800838: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x8080083C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800840: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80800844: beq         $s0, $zero, L_80800884
    if (ctx->r16 == 0) {
        // 0x80800848: addu        $a2, $t5, $t6
        ctx->r6 = ADD32(ctx->r13, ctx->r14);
            goto L_80800884;
    }
    // 0x80800848: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
L_8080084C:
    // 0x8080084C: lhu         $t7, 0x6($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X6);
    // 0x80800850: andi        $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 & 0X4000;
    // 0x80800854: beq         $t8, $zero, L_8080087C
    if (ctx->r24 == 0) {
        // 0x80800858: nop
    
            goto L_8080087C;
    }
    // 0x80800858: nop

    // 0x8080085C: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80800860: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x80800864: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80800868: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x8080086C: lh          $t1, -0x4($v1)
    ctx->r9 = MEM_H(ctx->r3, -0X4);
    // 0x80800870: sh          $t1, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r9;
    // 0x80800874: lh          $t2, -0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, -0X2);
    // 0x80800878: sh          $t2, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r10;
L_8080087C:
    // 0x8080087C: bne         $t0, $zero, L_8080084C
    if (ctx->r8 != 0) {
        // 0x80800880: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_8080084C;
    }
    // 0x80800880: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
L_80800884:
    // 0x80800884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800888: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080088C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800890: jr          $ra
    // 0x80800894: nop

    return;
    // 0x80800894: nop

    // 0x80800898: nop

    // 0x8080089C: nop

;}
RECOMP_FUNC void _bsledge_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800837E0: syscall     74
    recomp_syscall_handler(rdram, ctx, 0x800837E0);
    return;
    // 0x800837E4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _chlagoonufoint_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A40: syscall     190
    recomp_syscall_handler(rdram, ctx, 0x80085A40);
    return;
    // 0x80085A44: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808000EC_charmouredcaveman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000F8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808000FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800100: jal         0x8010D23C
    // 0x80800104: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    func_8010D23C(rdram, ctx);
        goto after_0;
    // 0x80800104: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_0:
    // 0x80800108: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8080010C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800110: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800118: srl         $t7, $v1, 10
    ctx->r15 = S32(U32(ctx->r3) >> 10);
    // 0x8080011C: beq         $t7, $at, L_80800150
    if (ctx->r15 == ctx->r1) {
        // 0x80800120: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_80800150;
    }
    // 0x80800120: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80800124: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80800128: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080012C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800130: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x80800134: lui         $a2, 0xC120
    ctx->r6 = S32(0XC120 << 16);
    // 0x80800138: jal         0x80089F20
    // 0x8080013C: lui         $a3, 0x430C
    ctx->r7 = S32(0X430C << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x8080013C: lui         $a3, 0x430C
    ctx->r7 = S32(0X430C << 16);
    after_1:
    // 0x80800140: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800144: andi        $a1, $v0, 0x8
    ctx->r5 = ctx->r2 & 0X8;
    // 0x80800148: srl         $t9, $v1, 10
    ctx->r25 = S32(U32(ctx->r3) >> 10);
    // 0x8080014C: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_80800150:
    // 0x80800150: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x80800154: sltiu       $at, $t0, 0x7
    ctx->r1 = ctx->r8 < 0X7 ? 1 : 0;
    // 0x80800158: beq         $at, $zero, L_8080030C
    if (ctx->r1 == 0) {
        // 0x8080015C: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8080030C;
    }
    // 0x8080015C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800160: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1116, 0XA20) << 16);
    // 0x80800164: addu        $at, $at, $t0
    gpr jr_addend_8080016C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800168: lw          $t0, 0xA20($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1116, 0XA20));
    // 0x8080016C: jr          $t0
    // 0x80800170: nop

    switch (jr_addend_8080016C >> 2) {
        case 0: goto L_80800174; break;
        case 1: goto L_808001E4; break;
        case 2: goto L_808001F4; break;
        case 3: goto L_80800238; break;
        case 4: goto L_80800284; break;
        case 5: goto L_808002B8; break;
        case 6: goto L_80800304; break;
        default: switch_error(__func__, 0x8080016C, 0x80800A20);
    }
    // 0x80800170: nop

L_80800174:
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x80800640
    // 0x8080017C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80800640_charmouredcaveman(rdram, ctx);
        goto after_2;
    // 0x8080017C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80800180: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800184: beql        $a1, $zero, L_80800198
    if (ctx->r5 == 0) {
        // 0x80800188: lw          $t1, 0x30($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X30);
            goto L_80800198;
    }
    goto skip_0;
    // 0x80800188: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x8080018C: jal         0x808009D4
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009D4_charmouredcaveman(rdram, ctx);
        goto after_3;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800194: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
L_80800198:
    // 0x80800198: beql        $t1, $zero, L_80800310
    if (ctx->r9 == 0) {
        // 0x8080019C: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_80800310;
    }
    goto skip_1;
    // 0x8080019C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x808001A0: jal         0x8010D278
    // 0x808001A4: nop

    func_8010D278(rdram, ctx);
        goto after_4;
    // 0x808001A4: nop

    after_4:
    // 0x808001A8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x808001AC: beq         $v0, $at, L_8080030C
    if (ctx->r2 == ctx->r1) {
        // 0x808001B0: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080030C;
    }
    // 0x808001B0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001B4: jal         0x8010C9B0
    // 0x808001B8: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    func_8010C9B0(rdram, ctx);
        goto after_5;
    // 0x808001B8: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    after_5:
    // 0x808001BC: beql        $v0, $zero, L_80800310
    if (ctx->r2 == 0) {
        // 0x808001C0: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_80800310;
    }
    goto skip_2;
    // 0x808001C0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x808001C4: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808001D0: andi        $t3, $t2, 0xFFF7
    ctx->r11 = ctx->r10 & 0XFFF7;
    // 0x808001D4: jal         0x80102424
    // 0x808001D8: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x808001D8: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    after_6:
    // 0x808001DC: b           L_80800310
    // 0x808001E0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_80800310;
    // 0x808001E0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_808001E4:
    // 0x808001E4: jal         0x80800640
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800640_charmouredcaveman(rdram, ctx);
        goto after_7;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808001EC: b           L_8080030C
    // 0x808001F0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
        goto L_8080030C;
    // 0x808001F0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_808001F4:
    // 0x808001F4: jal         0x8080072C
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080072C_charmouredcaveman(rdram, ctx);
        goto after_8;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808001FC: jal         0x80101DDC
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_9;
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800204: beql        $v0, $zero, L_80800310
    if (ctx->r2 == 0) {
        // 0x80800208: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_80800310;
    }
    goto skip_3;
    // 0x80800208: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    skip_3:
    // 0x8080020C: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x80800210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800214: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x80800218: bgez        $t6, L_80800228
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080021C: nop
    
            goto L_80800228;
    }
    // 0x8080021C: nop

    // 0x80800220: b           L_80800228
    // 0x80800224: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80800228;
    // 0x80800224: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80800228:
    // 0x80800228: jal         0x80102424
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800230: b           L_80800310
    // 0x80800234: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_80800310;
    // 0x80800234: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80800238:
    // 0x80800238: jal         0x808008B0
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008B0_charmouredcaveman(rdram, ctx);
        goto after_11;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800240: jal         0x80101DDC
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_12;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800248: beql        $v0, $zero, L_80800310
    if (ctx->r2 == 0) {
        // 0x8080024C: lw          $t9, 0x34($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X34);
            goto L_80800310;
    }
    goto skip_4;
    // 0x8080024C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x80800250: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800258: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8080025C: bgez        $t9, L_80800274
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800260: nop
    
            goto L_80800274;
    }
    // 0x80800260: nop

    // 0x80800264: jal         0x8080095C
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080095C_charmouredcaveman(rdram, ctx);
        goto after_13;
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080026C: b           L_80800310
    // 0x80800270: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_80800310;
    // 0x80800270: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80800274:
    // 0x80800274: jal         0x80102424
    // 0x80800278: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800278: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x8080027C: b           L_80800310
    // 0x80800280: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_80800310;
    // 0x80800280: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80800284:
    // 0x80800284: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80800288: jal         0x8080092C
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080092C_charmouredcaveman(rdram, ctx);
        goto after_15;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800290: jal         0x80101DDC
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_16;
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800298: beq         $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x8080029C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080030C;
    }
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A0: jal         0x80102424
    // 0x808002A4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x808002A4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_17:
    // 0x808002A8: jal         0x80089CB8
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_5(rdram, ctx);
        goto after_18;
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808002B0: b           L_80800310
    // 0x808002B4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_80800310;
    // 0x808002B4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_808002B8:
    // 0x808002B8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x808002BC: jal         0x80089C90
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_19;
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808002C4: bne         $v0, $zero, L_808002D4
    if (ctx->r2 != 0) {
        // 0x808002C8: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_808002D4;
    }
    // 0x808002C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002CC: b           L_808002D4
    // 0x808002D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_808002D4;
    // 0x808002D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_808002D4:
    // 0x808002D4: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x808002D8: lbu         $t6, 0x75($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X75);
    // 0x808002DC: sll         $t4, $a1, 4
    ctx->r12 = S32(ctx->r5 << 4);
    // 0x808002E0: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x808002E4: andi        $t0, $a1, 0x1
    ctx->r8 = ctx->r5 & 0X1;
    // 0x808002E8: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x808002EC: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x808002F0: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x808002F4: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x808002F8: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x808002FC: b           L_8080030C
    // 0x80800300: sb          $t8, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r24;
        goto L_8080030C;
    // 0x80800300: sb          $t8, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r24;
L_80800304:
    // 0x80800304: jal         0x8080072C
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080072C_charmouredcaveman(rdram, ctx);
        goto after_20;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
L_8080030C:
    // 0x8080030C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80800310:
    // 0x80800310: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80800314: beql        $t9, $zero, L_80800360
    if (ctx->r25 == 0) {
        // 0x80800318: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800360;
    }
    goto skip_5;
    // 0x80800318: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x8080031C: beql        $t1, $zero, L_80800360
    if (ctx->r9 == 0) {
        // 0x80800320: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800360;
    }
    goto skip_6;
    // 0x80800320: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x80800324: jal         0x8010D278
    // 0x80800328: nop

    func_8010D278(rdram, ctx);
        goto after_21;
    // 0x80800328: nop

    after_21:
    // 0x8080032C: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80800330: beql        $v0, $at, L_80800348
    if (ctx->r2 == ctx->r1) {
        // 0x80800334: lui         $a1, 0x3E99
        ctx->r5 = S32(0X3E99 << 16);
            goto L_80800348;
    }
    goto skip_7;
    // 0x80800334: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    skip_7:
    // 0x80800338: jal         0x8010CD28
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_22;
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800340: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800344: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
L_80800348:
    // 0x80800348: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800350: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x80800354: jal         0x80102BF8
    // 0x80800358: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    func_80102BF8(rdram, ctx);
        goto after_23;
    // 0x80800358: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    after_23:
    // 0x8080035C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800360:
    // 0x80800360: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800364: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800368: jr          $ra
    // 0x8080036C: nop

    return;
    // 0x8080036C: nop

;}
RECOMP_FUNC void func_801001D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801001D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801001DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801001E0: jal         0x8010D1E8
    // 0x801001E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8010D1E8(rdram, ctx);
        goto after_0;
    // 0x801001E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x801001E8: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x801001EC: jal         0x801067C4
    // 0x801001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801067C4(rdram, ctx);
        goto after_1;
    // 0x801001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801001F4: beq         $v0, $zero, L_80100214
    if (ctx->r2 == 0) {
        // 0x801001F8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80100214;
    }
    // 0x801001F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_801001FC:
    // 0x801001FC: jal         0x80100120
    // 0x80100200: nop

    func_80100120(rdram, ctx);
        goto after_2;
    // 0x80100200: nop

    after_2:
    // 0x80100204: jal         0x8010682C
    // 0x80100208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010682C(rdram, ctx);
        goto after_3;
    // 0x80100208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8010020C: bne         $v0, $zero, L_801001FC
    if (ctx->r2 != 0) {
        // 0x80100210: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801001FC;
    }
    // 0x80100210: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80100214:
    // 0x80100214: jal         0x800FFB74
    // 0x80100218: nop

    func_800FFB74(rdram, ctx);
        goto after_4;
    // 0x80100218: nop

    after_4:
    // 0x8010021C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80100220: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80100224: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80100228: jr          $ra
    // 0x8010022C: nop

    return;
    // 0x8010022C: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E50: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E50);
    return;
    // 0x80083E54: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_800B39D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B39D0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800B39D4: multu       $a1, $t6
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B39D8: mflo        $t7
    ctx->r15 = lo;
    // 0x800B39DC: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x800B39E0: jr          $ra
    // 0x800B39E4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x800B39E4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
;}
RECOMP_FUNC void func_80800564_ch2dbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800568: sltiu       $at, $a2, 0xA
    ctx->r1 = ctx->r6 < 0XA ? 1 : 0;
    // 0x8080056C: beq         $at, $zero, L_808006EC
    if (ctx->r1 == 0) {
        // 0x80800570: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808006EC;
    }
    // 0x80800570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800574: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80800578: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1356, 0X900) << 16);
    // 0x8080057C: addu        $at, $at, $t6
    gpr jr_addend_80800584 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800580: lw          $t6, 0x900($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1356, 0X900));
    // 0x80800584: jr          $t6
    // 0x80800588: nop

    switch (jr_addend_80800584 >> 2) {
        case 0: goto L_8080058C; break;
        case 1: goto L_80800690; break;
        case 2: goto L_80800604; break;
        case 3: goto L_80800614; break;
        case 4: goto L_80800674; break;
        case 5: goto L_80800698; break;
        case 6: goto L_80800690; break;
        case 7: goto L_80800604; break;
        case 8: goto L_808006A8; break;
        case 9: goto L_808006C4; break;
        default: switch_error(__func__, 0x80800584, 0x80800900);
    }
    // 0x80800588: nop

L_8080058C:
    // 0x8080058C: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x80800590: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80800594: addiu       $t9, $a1, -0x2
    ctx->r25 = ADD32(ctx->r5, -0X2);
    // 0x80800598: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x8080059C: bnel        $t8, $at, L_808005B0
    if (ctx->r24 != ctx->r1) {
        // 0x808005A0: sltiu       $at, $t9, 0x11
        ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
            goto L_808005B0;
    }
    goto skip_0;
    // 0x808005A0: sltiu       $at, $t9, 0x11
    ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
    skip_0:
    // 0x808005A4: b           L_808006F0
    // 0x808005A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006F0;
    // 0x808005A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808005AC: sltiu       $at, $t9, 0x11
    ctx->r1 = ctx->r25 < 0X11 ? 1 : 0;
L_808005B0:
    // 0x808005B0: beq         $at, $zero, L_808006EC
    if (ctx->r1 == 0) {
        // 0x808005B4: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808006EC;
    }
    // 0x808005B4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808005B8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1356, 0X928) << 16);
    // 0x808005BC: addu        $at, $at, $t9
    gpr jr_addend_808005C4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808005C0: lw          $t9, 0x928($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1356, 0X928));
    // 0x808005C4: jr          $t9
    // 0x808005C8: nop

    switch (jr_addend_808005C4 >> 2) {
        case 0: goto L_808005CC; break;
        case 1: goto L_808005CC; break;
        case 2: goto L_808005DC; break;
        case 3: goto L_808005EC; break;
        case 4: goto L_808006EC; break;
        case 5: goto L_808005F4; break;
        case 6: goto L_808005EC; break;
        case 7: goto L_808005EC; break;
        case 8: goto L_808006EC; break;
        case 9: goto L_808006EC; break;
        case 10: goto L_808006EC; break;
        case 11: goto L_808006EC; break;
        case 12: goto L_808006EC; break;
        case 13: goto L_808006EC; break;
        case 14: goto L_808006EC; break;
        case 15: goto L_808006EC; break;
        case 16: goto L_808005EC; break;
        default: switch_error(__func__, 0x808005C4, 0x80800928);
    }
    // 0x808005C8: nop

L_808005CC:
    // 0x808005CC: jal         0x80800700
    // 0x808005D0: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_80800700_ch2dbaddy(rdram, ctx);
        goto after_0;
    // 0x808005D0: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_0:
    // 0x808005D4: b           L_808006F0
    // 0x808005D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006F0;
    // 0x808005D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005DC:
    // 0x808005DC: jal         0x80800700
    // 0x808005E0: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_80800700_ch2dbaddy(rdram, ctx);
        goto after_1;
    // 0x808005E0: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_1:
    // 0x808005E4: b           L_808006F0
    // 0x808005E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006F0;
    // 0x808005E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005EC:
    // 0x808005EC: b           L_808006F0
    // 0x808005F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006F0;
    // 0x808005F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005F4:
    // 0x808005F4: jal         0x8008A148
    // 0x808005F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x808005F8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x808005FC: b           L_808006F0
    // 0x80800600: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006F0;
    // 0x80800600: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800604:
    // 0x80800604: jal         0x80800700
    // 0x80800608: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_80800700_ch2dbaddy(rdram, ctx);
        goto after_3;
    // 0x80800608: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_3:
    // 0x8080060C: b           L_808006F0
    // 0x80800610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006F0;
    // 0x80800610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800614:
    // 0x80800614: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800618: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080061C: jal         0x800D9058
    // 0x80800620: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D9058(rdram, ctx);
        goto after_4;
    // 0x80800620: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_4:
    // 0x80800624: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800628: andi        $t1, $v0, 0x1FF
    ctx->r9 = ctx->r2 & 0X1FF;
    // 0x8080062C: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    // 0x80800630: lhu         $t2, 0x6E($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0X6E);
    // 0x80800634: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    // 0x80800638: lw          $a1, 0x54($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X54);
    // 0x8080063C: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x80800640: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800644: jal         0x8010297C
    // 0x80800648: sh          $t4, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r12;
    func_8010297C(rdram, ctx);
        goto after_5;
    // 0x80800648: sh          $t4, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r12;
    after_5:
    // 0x8080064C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800650: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800654: lhu         $t5, 0x72($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X72);
    // 0x80800658: srl         $t6, $t5, 10
    ctx->r14 = S32(U32(ctx->r13) >> 10);
    // 0x8080065C: bne         $t6, $at, L_8080066C
    if (ctx->r14 != ctx->r1) {
        // 0x80800660: nop
    
            goto L_8080066C;
    }
    // 0x80800660: nop

    // 0x80800664: jal         0x80800700
    // 0x80800668: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_80800700_ch2dbaddy(rdram, ctx);
        goto after_6;
    // 0x80800668: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_6:
L_8080066C:
    // 0x8080066C: b           L_808006F0
    // 0x80800670: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006F0;
    // 0x80800670: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800674:
    // 0x80800674: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x80800678: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8080067C: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800680: beql        $t8, $at, L_808006F0
    if (ctx->r24 == ctx->r1) {
        // 0x80800684: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808006F0;
    }
    goto skip_1;
    // 0x80800684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80800688: b           L_808006F0
    // 0x8080068C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006F0;
    // 0x8080068C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800690:
    // 0x80800690: b           L_808006F0
    // 0x80800694: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006F0;
    // 0x80800694: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800698:
    // 0x80800698: jal         0x80800700
    // 0x8080069C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800700_ch2dbaddy(rdram, ctx);
        goto after_7;
    // 0x8080069C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_7:
    // 0x808006A0: b           L_808006F0
    // 0x808006A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006F0;
    // 0x808006A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006A8:
    // 0x808006A8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x808006AC: bne         $a1, $at, L_808006BC
    if (ctx->r5 != ctx->r1) {
        // 0x808006B0: nop
    
            goto L_808006BC;
    }
    // 0x808006B0: nop

    // 0x808006B4: jal         0x801020DC
    // 0x808006B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_801020DC(rdram, ctx);
        goto after_8;
    // 0x808006B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
L_808006BC:
    // 0x808006BC: b           L_808006F0
    // 0x808006C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006F0;
    // 0x808006C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006C4:
    // 0x808006C4: lw          $t9, 0x64($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X64);
    // 0x808006C8: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x808006CC: bgez        $t2, L_808006E4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x808006D0: nop
    
            goto L_808006E4;
    }
    // 0x808006D0: nop

    // 0x808006D4: jal         0x8008A148
    // 0x808006D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_9;
    // 0x808006D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x808006DC: b           L_808006F0
    // 0x808006E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006F0;
    // 0x808006E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006E4:
    // 0x808006E4: b           L_808006F0
    // 0x808006E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006F0;
    // 0x808006E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808006EC:
    // 0x808006EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006F0:
    // 0x808006F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006F8: jr          $ra
    // 0x808006FC: nop

    return;
    // 0x808006FC: nop

;}
RECOMP_FUNC void _chpumproomgrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E80: syscall     253
    recomp_syscall_handler(rdram, ctx, 0x80085E80);
    return;
    // 0x80085E84: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800A0DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0DC4: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0DC8: jr          $ra
    // 0x800A0DCC: sb          $a1, 0x15($t6)
    MEM_B(0X15, ctx->r14) = ctx->r5;
    return;
    // 0x800A0DCC: sb          $a1, 0x15($t6)
    MEM_B(0X15, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _sujiggy_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A6B8: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A6B8);
    return;
    // 0x8008A6BC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800D3C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3C70: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D3C74: lh          $a0, -0x4C04($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4C04);
    // 0x800D3C78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D3C7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D3C80: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D3C84: beq         $a0, $zero, L_800D3CE4
    if (ctx->r4 == 0) {
        // 0x800D3C88: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800D3CE4;
    }
    // 0x800D3C88: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D3C8C: jal         0x800B2890
    // 0x800D3C90: nop

    func_800B2890(rdram, ctx);
        goto after_0;
    // 0x800D3C90: nop

    after_0:
    // 0x800D3C94: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D3C98: jal         0x800B28C4
    // 0x800D3C9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    vector_begin(rdram, ctx);
        goto after_1;
    // 0x800D3C9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800D3CA0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D3CA4: jal         0x800B296C
    // 0x800D3CA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    vector_end(rdram, ctx);
        goto after_2;
    // 0x800D3CA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800D3CAC: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x800D3CB0: beq         $at, $zero, L_800D3CD0
    if (ctx->r1 == 0) {
        // 0x800D3CB4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800D3CD0;
    }
    // 0x800D3CB4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800D3CB8:
    // 0x800D3CB8: jal         0x800D3BC8
    // 0x800D3CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D3BC8(rdram, ctx);
        goto after_3;
    // 0x800D3CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800D3CC0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x800D3CC4: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800D3CC8: bne         $at, $zero, L_800D3CB8
    if (ctx->r1 != 0) {
        // 0x800D3CCC: nop
    
            goto L_800D3CB8;
    }
    // 0x800D3CCC: nop

L_800D3CD0:
    // 0x800D3CD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D3CD4: jal         0x800B2D48
    // 0x800D3CD8: lh          $a0, -0x4C04($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4C04);
    func_800B2D48(rdram, ctx);
        goto after_4;
    // 0x800D3CD8: lh          $a0, -0x4C04($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4C04);
    after_4:
    // 0x800D3CDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D3CE0: sh          $zero, -0x4C04($at)
    MEM_H(-0X4C04, ctx->r1) = 0;
L_800D3CE4:
    // 0x800D3CE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3CE8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D3CEC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D3CF0: jr          $ra
    // 0x800D3CF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800D3CF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void basub_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008E0: jal         0x80085458
    // 0x808008E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bawobble_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808008E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808008E8: jal         0x808000CC
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000CC_basub(rdram, ctx);
        goto after_1;
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808008F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808008F4: lw          $t6, 0x130($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X130);
    // 0x808008F8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(616, 0XC30) << 16);
    // 0x808008FC: addiu       $a2, $a2, 0xC30
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(616, 0XC30));
    // 0x80800900: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x80800904: lw          $t7, 0x130($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X130);
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080090C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800910: swc1        $f0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f0.u32l;
    // 0x80800914: lw          $v1, 0x130($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X130);
    // 0x80800918: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8080091C: jal         0x8009D454
    // 0x80800920: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    func_8009D454(rdram, ctx);
        goto after_2;
    // 0x80800920: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    after_2:
    // 0x80800924: lw          $t8, 0x130($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X130);
    // 0x80800928: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080092C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800930: sb          $v0, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r2;
    // 0x80800934: lw          $t9, 0x130($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X130);
    // 0x80800938: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080093C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800940: swc1        $f6, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f6.u32l;
    // 0x80800944: lw          $t0, 0x130($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X130);
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080094C: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x80800950: lw          $v1, 0x130($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X130);
    // 0x80800954: lwc1        $f10, 0x18($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800958: swc1        $f10, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f10.u32l;
    // 0x8080095C: lw          $t1, 0x130($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X130);
    // 0x80800960: swc1        $f0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f0.u32l;
    // 0x80800964: lw          $t2, 0x130($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X130);
    // 0x80800968: swc1        $f0, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f0.u32l;
    // 0x8080096C: lw          $t3, 0x130($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X130);
    // 0x80800970: jal         0x808004C8
    // 0x80800974: swc1        $f0, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f0.u32l;
    func_808004C8_basub(rdram, ctx);
        goto after_3;
    // 0x80800974: swc1        $f0, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f0.u32l;
    after_3:
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080097C: jal         0x80800B60
    // 0x80800980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    basub_entrypoint_15(rdram, ctx);
        goto after_4;
    // 0x80800980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800988: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080098C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800990: jr          $ra
    // 0x80800994: nop

    return;
    // 0x80800994: nop

;}
RECOMP_FUNC void bskaz_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080014C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800150: jal         0x8009EA2C
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009EA2C(rdram, ctx);
        goto after_0;
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800158: beq         $v0, $zero, L_80800168
    if (ctx->r2 == 0) {
        // 0x8080015C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800168;
    }
    // 0x8080015C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800160: b           L_8080016C
    // 0x80800164: addiu       $v0, $zero, 0x18B
    ctx->r2 = ADD32(0, 0X18B);
        goto L_8080016C;
    // 0x80800164: addiu       $v0, $zero, 0x18B
    ctx->r2 = ADD32(0, 0X18B);
L_80800168:
    // 0x80800168: addiu       $v0, $zero, 0xC2
    ctx->r2 = ADD32(0, 0XC2);
L_8080016C:
    // 0x8080016C: jr          $ra
    // 0x80800170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800818_chmrsicecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800818: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080081C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800820: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800824: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800828: jal         0x8080066C
    // 0x8080082C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8080066C_chmrsicecube(rdram, ctx);
        goto after_0;
    // 0x8080082C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800830: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1204, 0XA74) << 16);
    // 0x80800834: addiu       $t6, $t6, 0xA74
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1204, 0XA74));
    // 0x80800838: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x8080083C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800840: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800844: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800848: jal         0x800BBCB8
    // 0x8080084C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x8080084C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_1:
    // 0x80800850: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1204, 0XA64) << 16);
    // 0x80800854: addiu       $a2, $a2, 0xA64
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1204, 0XA64));
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080085C: jal         0x80089D18
    // 0x80800860: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800860: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80800864: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800868: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080086C: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800870: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800874: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800878: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080087C: jal         0x801094E0
    // 0x80800880: nop

    func_801094E0(rdram, ctx);
        goto after_3;
    // 0x80800880: nop

    after_3:
    // 0x80800884: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800888: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080088C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800890: jr          $ra
    // 0x80800894: nop

    return;
    // 0x80800894: nop

;}
